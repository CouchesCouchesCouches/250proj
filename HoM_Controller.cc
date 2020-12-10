/** \file HoM_Controller.cc
 *  \todo clean Clean code when it is simple.
 *  \todo doc Write doxygen documentation.
 *  \authors cldurand,takaakimatsuo
 *  \date 2018/04/01
 *
 *  \brief HoM_Controller
 */
#include "HoM_Controller.h"
#include "globals.h"
#include "yen.h"
using namespace YEN;

namespace quisp {
namespace modules {

Define_Module(HoM_Controller);

HoM_Controller::HoM_Controller()
{

}

void HoM_Controller::initialize(int stage)
{
    time_out_count = 0;
    current_trial_id = dblrand();
    handshake = false;
    auto_resend_BSANotifier = true;
    BSA_timeout = 1e-6;
    address = par("address");
    receiver = par("receiver");
    passive = par("passive");
    /** \todo This code looks awefully simplifiable */
    if (passive) {
        //Nothing to do. EPPS will take care of entanglement creation.
        //max_buffer also stays unknown, until this gets a message about that info from epps.
        //Therefore, if passive, max_buffer has to be update manually every time when you get a packet from epps.
        //It still needs to know who is the neighbor of this internal hom (a.k.a qnic)
        checkNeighborAddress(true);
    } else if (receiver) {
        internodeInitializer();//Other parameter settings
    } else if (!receiver) {
        standaloneInitializer();//Other parameter settings
    } else {
        error("Set receiver parameter of HoM to true or false.");
    }
}


//Initialization of the HoM module inside a QNode.
//The initialization will be a little bit different from the stand-alone HoM module.
//For example, you don't need to check both of the neighbors because it is inside a QNode.
void HoM_Controller::internodeInitializer(){
    checkNeighborAddress(true);
    checkNeighborBuffer(true);
    updateIDE_Parameter(true);

    accepted_burst_interval = (double)1/(double)photon_detection_per_sec;
    BSAstart *generatePacket = new BSAstart;
    scheduleAt(simTime()+par("Initial_notification_timing_buffer"),generatePacket);
    //scheduleAt(simTime(),generatePacket);
}

//Initialization of the stand-alone HoM module.
void HoM_Controller::standaloneInitializer(){
    //Just in case, check if the 2 quantum port of the node
    if(getParentModule()->gateSize("quantum_port")!=2){
        error("No more or less than 2 neighbors are allowed for HoM.",getParentModule()->gateSize("quantum_port"));
                endSimulation();
    }
    checkNeighborAddress(false);
    checkNeighborBuffer(false);
    updateIDE_Parameter(false);

    accepted_burst_interval = (double)1/(double)photon_detection_per_sec;
    BSAstart *generatePacket = new BSAstart;
    scheduleAt(simTime()+par("Initial_notification_timing_buffer"),generatePacket);
    //scheduleAt(simTime(),generatePacket);
}

//This is invoked only once at the begining of the simulation.
//This method sends 2 classical BSA timing notifiers to neighbors (or to itself).
//During the simulation, this method is not needed because this information is piggybacked when the node returns the results of entanglement attempt.
void HoM_Controller::sendNotifiers(){
     double time = calculateTimeToTravel(max_neighbor_distance,speed_of_light_in_channel);//When the packet reaches = simitme()+time
     BSMtimingNotifier *pk = generateNotifier(time, speed_of_light_in_channel, distance_to_neighbor, neighbor_address, accepted_burst_interval,photon_detection_per_sec, max_buffer);
     double first_nodes_timing = calculateEmissionStartTime(time,distance_to_neighbor,speed_of_light_in_channel);
     pk->setTiming_at(first_nodes_timing);//Tell neighboring nodes to shoot photons so that the first one arrives at BSA at the specified timing
     if(receiver){
         pk->setInternal_qnic_index(qnic_index);
         pk->setInternal_qnic_address(qnic_address);
     }

     BSMtimingNotifier *pkt = generateNotifier(time, speed_of_light_in_channel, distance_to_neighbor_two, neighbor_address_two, accepted_burst_interval,photon_detection_per_sec, max_buffer);
     double second_nodes_timing = calculateEmissionStartTime(time,distance_to_neighbor_two,speed_of_light_in_channel);
     pkt->setTiming_at(second_nodes_timing);//Tell neighboring nodes to shoot photons so that the first one arrives at BSA at the specified timing
     //If you want some uncertainty in timing calculation, maybe second_nodes_timing+uniform(-n,n) helps
     try{
         send(pk, "toRouter_port");//send to port out. connected to local routing module (routing.localIn).
         send(pkt, "toRouter_port");
     }catch(cTerminationException& e) {
         error("Error in HoM_Controller.cc. It does not have port named toRouter_port.");
         endSimulation();
     }catch (std::exception& e) {
         error("Error in HoM_Controller.cc. It does not have port named toRouter_port.");
         endSimulation();
     }
}




void HoM_Controller::handleMessage(cMessage *msg){
	//std::cout<<"HoMReceiving result\n";
	//std::cout<<msg<<", bsa? ="<<(bool)( dynamic_cast<BSAresult *>(msg) != nullptr)<<"\n"; //Omnet somehow bugs without this... it receives a msg correctly from BellStateAnalyzer, but very rarely does not recognize the type. VERY weird.
    
	if(dynamic_cast<BSAstart *>(msg) != nullptr){
		//std::cout<<"Generate packet\n";
        sendNotifiers();
		delete msg;
		return;
        //Create timeout
    } else if(dynamic_cast<BSAresult *>(msg) != nullptr){
		//std::cout<<"BSAresult\n";
        auto_resend_BSANotifier = false;//Photon is arriving. No need to auto reschedule next round. Wait for the last photon fron either node.
        bubble("BSAresult accumulated");
        BSAresult *pk = check_and_cast<BSAresult *>(msg);
		bool entangled = pk->getEntangled();
		//std::cout<<"Accumulating "<<entangled<<"\n";

        int prev = getStoredBSAresultsSize();
        pushToBSAresults(entangled);
        int aft = getStoredBSAresultsSize();
		if(prev+1 != aft){
			error("Nahnah nah!");
		}
        /*if(getStoredBSAresultsSize() == max_buffer && handshake==true){
            bubble("All results stored!");
            sendBSAresultsToNeighbors();
            clearBSAresults();
        }else{

        }*/
    }else if(dynamic_cast<BSAfinish *>(msg) != nullptr){//Last photon from either node arrived.
		//std::cout<<"BSAfinish\n";
        bubble("BSAresult accumulated");
        BSAfinish *pk = check_and_cast<BSAfinish *>(msg);
        pushToBSAresults(pk->getEntangled());

        int stored = getStoredBSAresultsSize();
        char moge[sizeof(stored)];
        sprintf(moge, "%d", stored);
        bubble(moge);

        // Track link states of HoMs
        setLinkState();

        // setup end to end entanglements only if last HoM
        int thisaddr = getParentModule()->par("address");
        // std::cout << "BSA finish for address: " << thisaddr <<"\n";
        thisaddr -= 10;
        if(thisaddr == 22) {
            // std::cout << "consume links: " << thisaddr <<"\n";
            consumeLinks(); // Using the link states, set up end to end entanglement
            recover(major_paths[0]);
        }

        bubble("done");
        sendBSAresultsToNeighbors();//memory leak
        clearBSAresults();
        auto_resend_BSANotifier = true;
        current_trial_id = dblrand();
        //Schedule a checker with a time-out t, to see if both actually sent something.
        //Worst case is, when both have no free qubit, and no qubits get transmitted. In that case, this module needs to recognize that problem, and reschedule/resend the request after a cetrain time.
    }else if(dynamic_cast<BSAtimeoutChecker*>(msg) != nullptr){
		//std::cout<<"BSAtimeout\n";
        //std::cout<<"timeout check at"<<simTime()<<"\n";
        BSAtimeoutChecker *pk = check_and_cast<BSAtimeoutChecker *>(msg);
        if(auto_resend_BSANotifier == true && pk->getTrial_id() == current_trial_id){
            //No photon came from both nodes. All of the resources must have been busy that time.
            //error("there you go..");
        }
        //error("Timeout");
    }else{
		std::cout<<"Wait what?\n";
	}
    delete msg;
}


//This method checks the address of the neighbors.
//If it is a receiver, meaning that it is a internode, then it checks one neighbor address and stores its own QNode address.
void HoM_Controller::checkNeighborAddress(bool receiver){
    if(receiver){
        try{
            qnic_index = getParentModule()->getParentModule()->getIndex();
            qnic_address = getParentModule()->getParentModule()->par("self_qnic_address");
            neighbor_address = getQNode()->par("address");
            neighbor_address_two =  getParentModule()->gate("quantum_port$o",1)->getNextGate()->getNextGate()->getNextGate()->getOwnerModule()->par("address");
            distance_to_neighbor = getParentModule()->par("internal_distance");
            distance_to_neighbor_two = getParentModule()->gate("quantum_port$o",1)->getNextGate()->getNextGate()->getChannel()->par("distance");
            max_neighbor_distance = std::max(distance_to_neighbor,distance_to_neighbor_two);
        }catch (std::exception& e) {
            error("Error in HoM_Controller.cc when getting neighbor addresses. Check internodeInitializer.");
            endSimulation();
        }
    }else{//Controller in a Stand alone HoM node
        try{
            neighbor_address =  getParentModule()->gate("quantum_port$o",0)->getNextGate()->getOwnerModule()->par("address");
            neighbor_address_two =  getParentModule()->gate("quantum_port$o",1)->getNextGate()->getOwnerModule()->par("address");
            distance_to_neighbor = getParentModule()->gate("quantum_port$o",0)->getChannel()->par("distance");
            distance_to_neighbor_two = getParentModule()->gate("quantum_port$o",1)->getChannel()->par("distance");
            max_neighbor_distance = std::max(distance_to_neighbor,distance_to_neighbor_two);
        }catch (std::exception& e) {
            error("Error in HoM_Controller.cc. Your stand-alone HoM module may not connected to the neighboring node (quantum_port).");
            endSimulation();
        }
    }

}

//Checks the buffer size of the connected qnics.
void HoM_Controller::checkNeighborBuffer(bool receiver){
    if(receiver){
        try{
            neighbor_buffer =  getParentModule()->getParentModule()->par("numBuffer");
            neighbor_buffer_two = getParentModule()->gate("quantum_port$o",1)->getNextGate()->getNextGate()->getNextGate()->getNextGate()->getOwnerModule()->par("numBuffer");
            max_buffer = std::min(neighbor_buffer,neighbor_buffer_two);//Both nodes should transmit the same amount of photons.
        }catch (std::exception& e) {
            error("Error in HoM_Controller.cc. HoM couldnt find parameter numBuffer in the neighbor's qnic.");
            endSimulation();
        }
    }else{
        try{
            neighbor_buffer =  getParentModule()->gate("quantum_port$o",0)->getNextGate()->getNextGate()->getOwnerModule()->par("numBuffer");
            neighbor_buffer_two =  getParentModule()->gate("quantum_port$o",1)->getNextGate()->getNextGate()->getOwnerModule()->par("numBuffer");
            max_buffer = std::min(neighbor_buffer,neighbor_buffer_two);//Both nodes should transmit the same amount of photons.
        }catch (std::exception& e) {
            error("Error in HoM_Controller.cc. HoM couldnt find parameter numBuffer in the neighbor's qnic.");
            endSimulation();
        }
    }
}

void HoM_Controller::updateIDE_Parameter(bool receiver){
    try{
        photon_detection_per_sec = (int)par("photon_detection_per_sec");
        if(photon_detection_per_sec <= 0){
            error("Photon detection per sec for HoM must be more than 0.");
        }
        par("neighbor_address") = neighbor_address;
        par("neighbor_address_two") = neighbor_address_two;
        par("distance_to_neighbor") = distance_to_neighbor;
        par("distance_to_neighbor_two") = distance_to_neighbor_two;
        par("max_neighbor_distance") = max_neighbor_distance;
        par("max_buffer") = max_buffer;
        c = &par("Speed_of_light_in_fiber");
        speed_of_light_in_channel = c->doubleValue();//per sec
        if(receiver){
            getParentModule()->par("qnic_index") = qnic_index;
        }
    }
    catch(std::exception& e){
        error(e.what());
        //std::cout<<"E="<<e.what()<<"\n";
        //error("photon_detection_per_sec is missing as a HoM_Controller parameter. Or maybe you should specify **.Speed_of_light_in_fiber = (number)km in .ini file.");
    }
}

//Generates a BSA timing notifier. This is also called only once for the same reason as sendNotifiers().
BSMtimingNotifier* HoM_Controller::generateNotifier(double time, double speed_of_light_in_channel, double distance_to_neighbor, int destAddr, double accepted_burst_interval,int photon_detection_per_sec, int max_buffer){
           BSMtimingNotifier *pk = new BSMtimingNotifier();
           //pk->setNumber_of_qubits(max_buffer);
           if(handshake==false)
               pk->setNumber_of_qubits(-1);//if -1, neighbors will keep shooting photons anyway.
           else
               pk->setNumber_of_qubits(max_buffer);
           pk->setSrcAddr(getParentModule()->par("address"));//packet source setting
           pk->setDestAddr(destAddr);
           pk->setKind(BSAtimingNotifier_type);
           pk->setInterval(accepted_burst_interval);
           pk->setAccepted_photons_per_sec(photon_detection_per_sec);//If very high, all photons can nearly be sent here(to BSA module) from neighboring nodes simultaneously
           double timing = calculateEmissionStartTime(time,distance_to_neighbor,speed_of_light_in_channel);
           pk->setTiming_at(timing);//Tell neighboring nodes to shoot photons so that the first one arrives at BSA at the specified timing
           return pk;
}

//Generates a packet that includes the BSA timing notifier and the BSA entanglement attempt results.
CombinedBSAresults* HoM_Controller::generateNotifier_c(double time, double speed_of_light_in_channel, double distance_to_neighbor, int destAddr, double accepted_burst_interval,int photon_detection_per_sec, int max_buffer){
           CombinedBSAresults *pk = new CombinedBSAresults();
           //pk->setNumber_of_qubits(max_buffer);
           if(handshake==false)
               pk->setNumber_of_qubits(-1);//if -1, neighbors will keep shooting photons anyway.
           else
               pk->setNumber_of_qubits(max_buffer);
           pk->setSrcAddr(getParentModule()->par("address"));//packet source setting
           pk->setDestAddr(destAddr);
           pk->setKind(BSAtimingNotifier_type);
           pk->setInterval(accepted_burst_interval);
           pk->setAccepted_photons_per_sec(photon_detection_per_sec);//If very high, all photons can nearly be sent here(to BSA module) from neighboring nodes simultaneously
           double timing = calculateEmissionStartTime(time,distance_to_neighbor,speed_of_light_in_channel);
           pk->setTiming_at(timing);//Tell neighboring nodes to shoot photons so that the first one arrives at BSA at the specified timing
           return pk;
}


//Depending on the distance to the neighbor QNIC, this calculates when the neighbor needs to start the emission.
//The farther node emits it instantaneously, while the closer one needs to wait because 2 photons need to arrive at HoM simultaneously.
double HoM_Controller::calculateEmissionStartTime(double time, double distance_to_node, double c){
    //distance_to_node is the distance to HoM to self
    double self_timeToTravel = calculateTimeToTravel(distance_to_node,c);
    if((self_timeToTravel) != time){//If shorter distance, then the node needs to wait a little for the other node with the longer distance
            return (time-self_timeToTravel)*2;//Waiting time
    }else{
        return 0;//No need to wait
    }
}

double HoM_Controller::calculateTimeToTravel(double distance, double c){
    return (distance/c);
}

void HoM_Controller::BubbleText(const char* txt){
    if (hasGUI()) {
      char text[32];
      sprintf(text, "%s", txt);
      bubble(text);
    }
}

cModule* HoM_Controller::getQNode(){
         cModule *currentModule = getParentModule();//We know that Connection manager is not the QNode, so start from the parent.
         try{
             cModuleType *QNodeType =  cModuleType::get("networks.QNode");//Assumes the node in a network has a type QNode
             while(currentModule->getModuleType()!=QNodeType){
                 currentModule = currentModule->getParentModule();
             }
             return currentModule;
         }catch(std::exception& e){
             error("No module with QNode type found. Have you changed the type name in ned file?");
             endSimulation();
         }
         return currentModule;
}





void HoM_Controller::pushToBSAresults(bool attempt_success){
	int prev = getStoredBSAresultsSize();
    results[getStoredBSAresultsSize()] = attempt_success;
	int aft = getStoredBSAresultsSize();
	if(prev+1 != aft){
		error("BSAresults not working correctly");
	}
}
int HoM_Controller::getStoredBSAresultsSize(){
    return results.size();
}

int HoM_Controller::entangledCount(){
    EV<<"\n***returning number of successfully entangled qubits\n\n";
    int counter = 0;
    for(auto it : results ){
        int index = it.first;
        bool entangled = it.second;
        if(entangled) {
            counter++;
        }
    }
    return counter;
}

void HoM_Controller::printBSAresults(){
    EV<<"\n***Printing contents of results[] in BSAresults\n\n";
    for(auto it : results ){
        int index = it.first;
        bool entangled = it.second;
        EV<<index<<" th, entangled = "<<entangled<<"\n";
    }
}
void HoM_Controller::clearBSAresults(){
    results.clear();
}

//Instead of sendNotifiers, we invoke this during the simulation to return the next BSA timing and the result.
//This should be simplified more.
void HoM_Controller::sendBSAresultsToNeighbors(){

    if(!passive){
        CombinedBSAresults *pk, *pkt;

        double time = calculateTimeToTravel(max_neighbor_distance,speed_of_light_in_channel);//When the packet reaches = simitme()+time
        pk = generateNotifier_c(time, speed_of_light_in_channel, distance_to_neighbor, neighbor_address, accepted_burst_interval,photon_detection_per_sec, max_buffer);
        double first_nodes_timing = calculateEmissionStartTime(time,distance_to_neighbor,speed_of_light_in_channel);
        pk->setTiming_at(first_nodes_timing);//Tell neighboring nodes to shoot photons so that the first one arrives at BSA at the specified timing


        pk->setSrcAddr(address);
        pk->setDestAddr(neighbor_address);
        pk->setList_of_failedArraySize(getStoredBSAresultsSize());
        pk->setKind(5);
        if(receiver){
                   pk->setInternal_qnic_index(qnic_index);
                   pk->setInternal_qnic_address(qnic_address);
        }

        pkt = generateNotifier_c(time, speed_of_light_in_channel, distance_to_neighbor_two, neighbor_address_two, accepted_burst_interval,photon_detection_per_sec, max_buffer);
        double second_nodes_timing = calculateEmissionStartTime(time,distance_to_neighbor_two,speed_of_light_in_channel);
        pkt->setTiming_at(second_nodes_timing);//Tell neighboring nodes to shoot photons so that the first one arrives at BSA at the specified timing
        //EV<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!list of failed size = "<<getStoredBSAresultsSize()<<"\n";
        pkt->setSrcAddr(address);
        pkt->setDestAddr(neighbor_address_two);
        pkt->setList_of_failedArraySize(getStoredBSAresultsSize());
        pkt->setKind(5);

        for(auto it : results ){
           int index = it.first;
           bool entangled = it.second;
		   //std::cout<<index<<" th, entangled = "<<entangled<<"\n";
           pk->setList_of_failed(index, entangled);
           pkt->setList_of_failed(index, entangled);
        }
        send(pk,"toRouter_port");
        send(pkt,"toRouter_port");

        //BSAtimeoutChecker *timeout = new BSAtimeoutChecker;//This is used to emit the next round's timing in case no photon arrived.
        //timeout->setTrial_id(current_trial_id);
        //std::cout<<"now = "<<simTime()<<"time = "<<time<<"\n";
        //scheduleAt(simTime()+2*(1.1*time), timeout);

    }else{//For SPDC type link
        CombinedBSAresults_epps *pk, *pkt;
        pk = new CombinedBSAresults_epps();
        pkt = new CombinedBSAresults_epps();

        pk->setSrcAddr(address);
        pk->setDestAddr(neighbor_address);
        pk->setList_of_failedArraySize(getStoredBSAresultsSize());
        pk->setKind(6);

        pkt->setSrcAddr(address);
        pkt->setDestAddr(neighbor_address_two);
        pkt->setList_of_failedArraySize(getStoredBSAresultsSize());
        pkt->setKind(6);

        //EV<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!list of failed size = "<<getStoredBSAresultsSize()<<"\n";

        for(auto it : results ){
           int index = it.first;
           bool entangled = it.second;
           pk->setList_of_failed(index, entangled);
           pkt->setList_of_failed(index, entangled);
        }
        send(pk,"toRouter_port");
        send(pkt,"toRouter_port");
    }
}


//When the BSA is passive, it does not know how many qubits to emit (because it depends on the neighbor's).
//Therefore, the EPPS sends a classical packet that includes such information.
//When CM receives it, it will also have to update the max_buffer of HoM_Controller, to know when the emission end and send the classical BSAresults to the neighboring EPPS.
void HoM_Controller::setMax_buffer(int buffer){
    Enter_Method("setMax_buffer()");
    if(!passive){
        return;
    }else{
        max_buffer = buffer;
        par("max_buffer") = buffer;
    }
}

// CUSTOM METHOD
// Adds or updates a pair of node# and linkstate/width for our array
void HoM_Controller::setLinkState() {
    // Track link states of HoMs
    EV << "-------------------------------------------\n";
    int counter = 0;
    for(auto it : results ){
        int index = it.first;
        bool entangled = it.second;
        if(entangled) {
            counter++;
        }
    }
    int thisaddr = getParentModule()->par("address");
    if(thisaddr >= 10){
        thisaddr -= 10;
        if(results.size() < 10){ //hard coded buffer size of whatever
            // add counter to current HoM link state in our Global array
            EV << " DEBUGBRO  \n";
            HoMstates[thisaddr] += counter;
        }
        else{
            // set HoM link state to counter in GLobal a
            HoMstates[thisaddr] = counter;
        }
    }
    EV << "HoM number " << thisaddr << " has link state " << counter <<"!!! \n";
    EV << "Total attempted entanglements:  "<< results.size() << "\n";;
    for(auto it : results ){
        int index = it.first;
        bool entangled = it.second;
        EV<< entangled<<" ";
    }
    EV << "\nPrint out HoM link states: \n";
        for(int i=0; i<23;i++ ){ // HARDCODED NUM OF HOMS TO 22
            EV<<"HoM " << i<<", entangled = "<<HoMstates[i]<<"\n";
        }
}

void HoM_Controller::consumeLinks() {

    std::cout <<"\n\n****************************************************\n";
    std::cout <<"************Adding to total entanglements***********\n";
    std::cout <<"****************************************************\n";
    std::cout << "totalEntanglements (before) = " << totalEntanglements << "\n";
    std::cout << "Print out HoM link states: \n";
    for(int i=0; i<23;i++ ){ // HARDCODED NUM OF HOMS TO 22
        std::cout<<"HoM " << i<<", entangled = "<<HoMstates[i]<<"\n";
    }

    std::cout << "major_paths.size() = " <<major_paths.size() << "\n";

    bool debug_flag = false;
    if(debug_flag) {
        for(int path = 0; path < major_paths.size(); path++) {
            //showlist_cout(major_paths[path]);
            std::cout << "path size = " << major_paths[path].size() << ": ";
            for(int node_index = 0; node_index < major_paths[path].size(); node_index++) {
                std::cout << major_paths[path][node_index] << " ";
            }
            std::cout <<"\n";
            std::cout << "HoM's in the path: \n";
            for(int node_index = 1; node_index < major_paths[path].size(); node_index += 2) { // HoMs are every other node starting from node 1
                int HoM_address = major_paths[path][node_index];
                int HoM_index = HoM_address - 10;
                std::cout << "HoMstates[" << HoM_index << "] = " << HoMstates[HoM_index] << "\n";
            }
            std::cout <<"\n";
        }
    }

    // actually do the decrementing ^^ this is all for debugging^
    std::cout <<"****************************************************\n";
    std::cout <<"**********Actually calculating entanglements*********\n";

    int max = totalEntanglements + NUM_END_TO_END_ENTANG; // maximum number of entanglements to have after
    int left_to_entangle = NUM_END_TO_END_ENTANG; // initially no entanglements made for this run
    int max_width = NUM_END_TO_END_ENTANG;
    int HoM_address;
    int HoM_index;
    int attempts;

    // using these paths, check the link states
    for(int path_index = 0; path_index < major_paths.size(); path_index++) {
        // copy the path so not pointing to same vector by reference
        vector<int> path;
        for(int i = 0; i < major_paths[path_index].size(); i++) {
            path.push_back(major_paths[path_index][i]);
        } // copied

        if(totalEntanglements == max) { // stop once max is reached
            EV << max << " end to end entanglements!\nEnd...\n";
            std::cout << max << " end to end entanglements!\nEnd...\n";
            break;
        }

        while(true) {
            std::cout << "Checking path " << path_index << " on attempt " << attempts <<": ";
            showlist_cout(path);
            std::cout << "\n";
            for(int node_index = 1; node_index < path.size(); node_index += 2) { // every other and start from 1 for HoM nodes
                HoM_address = path[node_index];
                HoM_index = HoM_address - 10;
                std::cout << "HoMstates[" << HoM_index << "] (node "<<HoM_address<<") = " << HoMstates[HoM_index] << "\n";
                //std::cout << "max_width = " << max_width << "\n";
                // check max_width along entire path and then decrement all by max_width
                if(HoMstates[HoM_index] < max_width) {
                    max_width = HoMstates[HoM_index];
                    if(max_width == 0) {
                        std::cout << "Found edge width of 0, skipping this path\n";
                        break;
                    }
                }
            }
            if(max_width == 0) { // failed path so find a recovery path
                std::cout << "Looking for a recovery path because max_width was 0\n";
                path = recover(path);
                if(path[0] == SOURCE_NODE) {
                    std::cout << "Successfully found a recovery path\n";
                    max_width = NUM_END_TO_END_ENTANG;
                }
                else { // no recovery path, just break
                    std::cout <<"Failed to find a recovery path\n";
                    break;
                }
            }
            else { // this is a successful path so keep going
                break;
            }
        }

        // take a working path and update totalEntanglements and HoMstates along the path
        if(max_width != 0) {
            // check if max_width is bigger than we need
            if(max_width > left_to_entangle) {
                max_width = left_to_entangle;
            }
            // decrement the widths
            for(int node_index = 1; node_index < path.size(); node_index += 2) {
                HoM_address = path[node_index];
                HoM_index = HoM_address - 10;// HoM have address into HoMstates = address - 10
                //EV << "HoMstates[" << HoMaddress << "] = " << HoMstates[HoMaddress] << "\n";
                // decrement all by max_width
                HoMstates[HoM_index] -= max_width;
            }
            // debug print statements: show which path we just added to
            EV << "Successfully used " << max_width << " links along path:";
            showlist(path);
            EV << "\n";

            std::cout << "Successfully used " << max_width << " links along path:";
            showlist_cout(path);
            std::cout << "\n";

            totalEntanglements += max_width; // add to total successful entanglements
            left_to_entangle -= max_width;
        }
        //debug stuff
        std::cout << "HoMstates after being consumed:\n";
        for(int node_index = 1; node_index < path.size(); node_index += 2) { // every other and start from 1 for HoM nodes
            HoM_address = path[node_index];
            HoM_index = HoM_address - 10;
            std::cout << "HoMstates[" << HoM_index << "] (node "<<HoM_address<<") = " << HoMstates[HoM_index] << "\n";
        }
        std::cout << "\n";
        //end debug stuff
        max_width = NUM_END_TO_END_ENTANG;
    }
    std::cout << "totalEntanglements (after) = " << totalEntanglements << "\n";

    //EV << "totalEntanglements (after) = " << totalEntanglements << "\n";
    return;
}

bool HoM_Controller::check_link_state(vector<int> segment){
    for (int i=1; i<segment.size(); i=i+2){ // only check HoM nodes
        int h = segment[i];
        std::cout << "HoMstates[" << h - 10 << "] = " << HoMstates[h-10] << "\n";
        if (HoMstates[h - 10] == 0){
            return false;
        }
    }
    return true;
}

/*
 * inputs:
 *  path to recover from
 * outputs:
 *  new recovery path that works if there is one
 *  NULL if there is not
 */

std::vector<int> HoM_Controller::recover(vector<int> path){
    std::cout <<"***********************************************************\n";
    std::cout <<"*******************CALLING recover()***********************\n";
    int k = 1;
    // find all segments
    vector<vector<int> > segments;
    for (int i=2; i<=path.size()-1; i=i+4) {  // skip HoM
        if (i == path.size()-1){ // if the current node is the last node
            vector<int> seg = slicing(path, i-2, i);
            segments.push_back(seg);
            break;
        }
        vector<int> seg = slicing(path, i-2, i+2);
        segments.push_back(seg);
    }
    std::cout << "path: ";
    showlist_cout(path);
    std::cout << "was broken into: \n";
    for(int i = 0; i < segments.size(); i++) {
        showlist_cout(segments[i]);
        std::cout <<"\n";
    }
    // remember that interconnecting nodes are stored twice

    //check if segments are viable
    for (int j=0; j<segments.size(); j++){
        std::cout << "Checking segment " << j << "\n";
        vector<int> seg = segments[j];
        // for each segment, check link_state
        vector<vector<int> > recov_segs;
        if (check_link_state(seg) == false){
            // int begin = seg.front();
            // int end = seg.back();
            // cout << begin << " to " << end << endl;
            build_graph();  // need to rebuild g before calling yen
            recov_segs = yen(qDGraph, seg.front(), seg.back(), 5); // get 5 other options for this broken segment
            std::cout << "Find 5 recovery paths using Yens\n";
            for (int i=1; i<recov_segs.size(); i++){
                showlist_cout(recov_segs[i]);
                std::cout <<"\n";
                if(check_link_state(recov_segs[i]) == true){
                    segments[j] = recov_segs[i];
                    break;
                }
            }
        }
    }

    // construct the recovery path for the given path
    vector<int> recovery_path;
    int curr, prev;
    for(int i = 0; i < segments.size(); i++) {
        for(int j = 0; j < segments[i].size(); j++) {
            curr = segments[i][j];
            if(i == 0 && j == 0) { // first node so dont check previous
                recovery_path.push_back(curr);
                prev = curr;
            }
            else {
                if(prev == curr) { // skip duplicate nodes connecting segments
                    continue;
                }
                recovery_path.push_back(curr);
                prev = curr;
            }
        }
    }

    std::cout << "Possible recovery path for given path:\n";
    showlist_cout(recovery_path);
    std::cout <<"\n";
    // print homstates for debugging
    for(int i = 1; i < recovery_path.size(); i+=2) {
        std::cout << "HoMstates["<<recovery_path[i] - 10 << "] = "<<HoMstates[recovery_path[i] - 10] << "\n";
    }
    if(check_link_state(recovery_path)) { // if the recovery path actually works, return it
        std::cout << " Found recovery path: ";
        showlist_cout(recovery_path);
        std::cout << "\n";
        return recovery_path;
    }
    vector<int> garbage;
    garbage.push_back(-1); // catch this for failure to find recovery path
    std::cout << "No recovery path found, returning: ";
    showlist_cout(garbage);
    std::cout << "\n";
    return garbage;
}


// populate a graph's edges
void HoM_Controller::build_graph() {
    //Create the graph built from the topology using weights as quantum channel distances
    EV <<"Populating graph of quantum channel distances\n";
    cTopology *topo2 = new cTopology("topo2");
    cMsgPar *yes = new cMsgPar();
    yes->setStringValue("yes");
    topo2->extractByParameter("includeInTopo",yes->str().c_str());//Any node that has a parameter includeInTopo will be included in routing
    delete(yes);
    if(topo2->getNumNodes()==0 || topo2==nullptr){//If no node with the parameter & value found, do nothing.
            return;
    }
    int V = topo2->getNumNodes();

    //Initialize channel weights for all existing links.
    for (int x = 0; x < topo2->getNumNodes(); x++) {//Traverse through all nodes
       for (int j = 0; j < topo2->getNode(x)->getNumOutLinks(); j++) {//Traverse through all links from a specific node.
           int address = topo2->getNode(x)->getModule()->par("address");
           int neighbor_address =  topo2->getNode(x)->getLinkOut(j)->getRemoteNode()->getModule()->par("address");
           int nodeNumber = neighbor_address % 10000000;
           double channel_dist = topo2->getNode(x)->getLinkOut(j)->getLocalGate()->getChannel()->par("distance");//Get assigned cost for each channel written in .ned file
           if(strstr(topo2->getNode(x)->getLinkOut(j)->getLocalGate()->getFullName(),"quantum")){
               EV <<"g.addEdge("<<x<<", "<< nodeNumber << ", " << channel_dist <<");\n";
               qDGraph.addEdge(x, nodeNumber, channel_dist);
           }
       }
    }
}// end build_graph

/*
void HoM_Controller::finish(){

}*/

} // namespace modules
} // namespace quisp
