/** \file Router.cc
 *  \todo clean Clean code when it is simple.
 *  \todo doc Write doxygen documentation.
 *  \authors takaakimatsuo
 *
 *  \brief Router
 */
#include <map>
#include <omnetpp.h>
#include <classical_messages_m.h> //Path selection: type = 1, Timing notifier for BMA: type = 4

/*
Create new function for initializing a cTopology
This cTopology has the quantum link distances
Create a graph from this cTopology
We will run Yen's algorithm on this graph
*/
#include "stdc++.h"
#include "yen.h"
using namespace YEN;
//#include <iostream>

using namespace omnetpp;
using namespace quisp::messages;

namespace quisp {
namespace modules {

/** \class Router Router.cc
 *  \todo Documentation of the class header.
 *
 *  \brief Router
 */
class Router : public cSimpleModule
{   private:
        int myAddress;

        typedef std::map<int, int> RoutingTable;  // destaddr -> gateindex
        RoutingTable rtable;
        cTopology *quantumTopo; // used for Yens

        // dictionary for converting node number to node name
        typedef std::map<int, std::string> NodeNames; // nodeNumber -> nodeModuleName
        NodeNames nnames;

    protected:
        virtual void initialize(int stage) override;
        virtual void handleMessage(cMessage *msg) override;
        virtual int numInitStages() const override {return 1;};
        virtual void initYens(); // initializes the yens_paths
        virtual double getQDist(int src, int dest); // return the quantum channel distance
        virtual void populateGraph(); // create and init edges for a graph
        virtual void yensTest(); // test from test.cc on github using dummy links
        virtual void initNames(); // create the nnames dictionary
        virtual void printNames();
};

Define_Module(Router);

void Router::initialize(int stage)
{
       EV<<"Routing table initialized \n";
       myAddress = getParentModule()->par("address");

       // test yens algorithm first
       yensTest();
       // create graph used for Yen's algorithm
       initYens();
       populateGraph();

       //Topology creation for routing table
       cTopology *topo = new cTopology("topo");
       cMsgPar *yes = new cMsgPar();
       yes->setStringValue("yes");
       topo->extractByParameter("includeInTopo",yes->str().c_str());//Any node that has a parameter includeInTopo will be included in routing
       delete(yes);
       if(topo->getNumNodes()==0 || topo==nullptr){//If no node with the parameter & value found, do nothing.
                return;
       }

       cTopology::Node *thisNode = topo->getNodeFor(getParentModule());//The parent node with this specific router

       int number_of_links_total = 0;

       //Initialize channel weights for all existing links.
       for (int x = 0; x < topo->getNumNodes(); x++) {//Traverse through all nodes
           //For Bidirectional channels, parameters are stored in LinkOut not LinkIn.
           for (int j = 0; j < topo->getNode(x)->getNumOutLinks(); j++) {//Traverse through all links from a specific node.
               //thisNode->disable();//You can also disable nodes or channels accordingly to represent broken hardwares
               EV<<"\n thisNode is "<< topo->getNode(x)->getModule()->getFullName() <<" has "<<topo->getNode(x)->getNumOutLinks()<<" links \n";
               double channel_cost = topo->getNode(x)->getLinkOut(j)->getLocalGate()->getChannel()->par("cost");//Get assigned cost for each channel written in .ned file

               EV<<topo->getNode(x)->getLinkOut(j)->getLocalGate()->getFullName()<<" =? "<<"includes quantum?"<<"\n";
               //if(strcmp(topo->getNode(x)->getLinkOut(j)->getLocalGate()->getChannel()->getFullName(),"QuantumChannel")==0){
               if(strstr(topo->getNode(x)->getLinkOut(j)->getLocalGate()->getFullName(),"quantum")){
                   //Ignore quantum link in classical routing table
                   EV<<"\n Disable quantum from topo \n";
                   topo->getNode(x)->getLinkOut(j)->disable();
               }else{
                   //Otherwise, keep the classical channels and set the weight
                   topo->getNode(x)->getLinkOut(j)->setWeight(channel_cost);//Set channel weight
                   EV<<"\n Including classical channel link cost = "<< topo->getNode(x)->getLinkOut(j)->getWeight()<<": "<<topo->getNode(x)->getLinkOut(j)->getLocalGate()->getChannel()->getFullName()<<"\n";
               }
           }
       }

       for (int i = 0; i < topo->getNumNodes(); i++) {//Traverse through all the destinations from the thisNode
               if (topo->getNode(i) == thisNode)
                   continue;  // skip the node that is running this specific router app
               //Apply dijkstra to each node to find all shortest paths.
               topo->calculateWeightedSingleShortestPathsTo(topo->getNode(i));//Overwrites getNumPaths() and so on.

               //Check the number of shortest paths towards the target node. This may be more than 1 if multiple paths have the same minimum cost.
               if (thisNode->getNumPaths() == 0)
                   continue;  // not connected

               cGate *parentModuleGate = thisNode->getPath(0)->getLocalGate();//Returns the next link/gate in the ith shortest paths towards the target node.
               int gateIndex = parentModuleGate->getIndex();
               int address = topo->getNode(i)->getModule()->par("address");
               rtable[address] = gateIndex;//Store gate index per destination from this node
               EV <<"\n  Classical!!!!: Towards address " << address <<"("<< topo->getNode(i)->getModule()->getName() << ")"<<parentModuleGate->getFullName()<<"gateIndex is " << gateIndex << "cost ="<< thisNode->getPath(0)->getWeight() << endl;

               if(strstr(parentModuleGate->getFullName(),"quantum")){
                   error("Classical routing table referring to quantum gates...");
               }
               EV << "\n  Towards address " << address <<"("<< topo->getNode(i)->getModule()->getName() << ") gateIndex is " << gateIndex << endl;
      }

      delete topo;
}


void Router::handleMessage(cMessage *msg)
{
        //check the header of the received package
        header *pk = check_and_cast<header *>(msg);
        int destAddr = pk->getDestAddr();//read destination from the packet
        int who_are_you = pk->getKind();//read the type of packet // This might be better fixed
        //bubble("Message kind "<<message_type<<" received");
        EV<<"destAddr ==== "<<destAddr <<"\n";

        //__if link tomography result, print contents
        if (dynamic_cast<LinkTomographyResult *>(msg)!= nullptr){
            EV << "(aaa):Received a LinkTomographyResult msg in Router.cc\n";
            EV << "Printing contents...\n";
            //EV << "getOutput_is_plus() =" << getOutput_is_plus() << "\n";
            //EV << "getBasis() =" << getBasis() << "\n";
            //EV << "getCount_id() =" << getCount_id() << "\n";
            //EV << "getPartner_address() =" << getPartner_address() << "\n";
            //EV << "getMax_count() =" << getMax_count() << "\n";
            //int maxCount = msg->getMax_count;
            //int getCount_id = msg->count_id();
            //EV <<"maxCount = "<< maxCount <<"\n";
            //EV <<"count_id = "<< getCount_id<<"\n";
        }

        if (destAddr == myAddress && who_are_you == 1) {//If destination is this node: Path selection 
            send(pk, "toApp");//send to Application locally
            return;
        }else if (destAddr == myAddress && dynamic_cast<BSMtimingNotifier *>(msg) != nullptr) {//Timing for BSM
            bubble("Timing Notifier from HoM (stand-alone or internal) received");
            send(pk, "rePort$o");//send to Application locally
            return;
        }else if (destAddr == myAddress && dynamic_cast<EPPStimingNotifier *>(msg) != nullptr) {//Timing for BSM
            bubble("Timing Notifier from EPPS received");
            send(pk, "rePort$o");//send to Application locally
            return;
        }else if (destAddr == myAddress && dynamic_cast<ConnectionSetupRequest *>(msg)!= nullptr){
            bubble("Connection setup request received");
            send(pk, "cmPort$o");
            return;
        }else if (destAddr == myAddress && dynamic_cast<ConnectionSetupResponse *>(msg)!= nullptr){
            bubble("Connection setup response received");
            send(pk, "cmPort$o");
            return;
        }else if (destAddr == myAddress && dynamic_cast<RejectConnectionSetupRequest *>(msg)!= nullptr){
            bubble("Reject connection setup response received");
            send(pk, "cmPort$o");
            return;
        }else if(destAddr == myAddress && dynamic_cast<InternalRuleSetForwarding *>(msg)!= nullptr){
            bubble("Internal RuleSet Forwarding packet received");
            send(pk, "rePort$o");
            return;
        }else if(destAddr == myAddress && dynamic_cast<InternalRuleSetForwarding_Application *>(msg)!= nullptr){
            bubble("Internal RuleSet Forwarding Application packet received");
            send(pk, "rePort$o");
            return;
        }else if(destAddr == myAddress && dynamic_cast<SwappingResult *>(msg)!= nullptr){
            bubble("Swapping Result packet received");
            send(pk, "rePort$o");
            return;
        }else if (destAddr == myAddress && dynamic_cast<LinkTomographyRequest *>(msg)!= nullptr){
            bubble("Link tomography request received");
            send(pk, "hmPort$o");
            return;
        }else if (destAddr == myAddress && dynamic_cast<LinkTomographyAck *>(msg)!= nullptr){
            bubble("Link tomography ack received");
            send(pk, "hmPort$o");
            return;
        }else if (destAddr == myAddress && dynamic_cast<LinkTomographyRuleSet *>(msg)!= nullptr){
            bubble("Link tomography rule set received");
            send(pk, "rePort$o");
            return;
        }else if (destAddr == myAddress && dynamic_cast<LinkTomographyResult *>(msg)!= nullptr){
            bubble("Link tomography result received");
            send(pk, "hmPort$o");
            return;
        }else if(destAddr == myAddress && dynamic_cast<PurificationResult *>(msg)!= nullptr){
            bubble("Purification result received");
            send(pk,"rePort$o");
            return;
        }else if(destAddr == myAddress && dynamic_cast<DoublePurificationResult *>(msg)!= nullptr){
            bubble("DoublePurification result received");
            send(pk,"rePort$o");
            return;
        }else if(destAddr == myAddress && dynamic_cast<DS_DoublePurificationResult *>(msg)!= nullptr){
            bubble("DS_DoublePurification result received");
            send(pk,"rePort$o");
            return;
        }else if(destAddr == myAddress && dynamic_cast<DS_DoublePurificationSecondResult *>(msg)!= nullptr){
            bubble("DS_DoublePurificationSecond result received");
            send(pk,"rePort$o");
            return;
        }else if(destAddr == myAddress && dynamic_cast<StopEmitting *>(msg)!= nullptr){
            send(pk,"rePort$o");
            return;
        }

        //Check if packet is reachable
        RoutingTable::iterator it = rtable.find(destAddr);
        if (it == rtable.end()) {
            std::cout <<"In Node["<<myAddress<<"]Address... " << destAddr << " unreachable, discarding packet " << pk->getName() << endl;
            delete pk;
            error("Router couldn't find the path. Shoudn't happen. Or maybe the router does not understand the packet.");
            return;
        }

        int outGateIndex = (*it).second;
        EV << "forwarding packet " << pk->getName() << " on gate index " << outGateIndex << endl;
        pk->setHopCount(pk->getHopCount()+1);
        send(pk, "toQueue", outGateIndex);
}

void Router::initYens() {
       EV<<"\nInitializing cTopology for quantum link distances\n";
       //Topology creation quantum links
       quantumTopo = new cTopology("quantumTopo");
       cMsgPar *yes = new cMsgPar();
       yes->setStringValue("yes");
       quantumTopo->extractByParameter("includeInTopo",yes->str().c_str());//Any node that has a parameter includeInTopo will be included in routing
       delete(yes);
       if(quantumTopo->getNumNodes()==0 || quantumTopo==nullptr){//If no node with the parameter & value found, do nothing.
                return;
       }

       cTopology::Node *thisNode = quantumTopo->getNodeFor(getParentModule());//The parent node with this specific router

       int number_of_links_total = 0;



       //Initialize channel weights for all existing links.
       for (int x = 0; x < quantumTopo->getNumNodes(); x++) {//Traverse through all nodes
           //For Bidirectional channels, parameters are stored in LinkOut not LinkIn.
           for (int j = 0; j < quantumTopo->getNode(x)->getNumOutLinks(); j++) {//Traverse through all links from a specific node.
               //thisNode->disable();//You can also disable nodes or channels accordingly to represent broken hardwares
               double channel_dist = quantumTopo->getNode(x)->getLinkOut(j)->getLocalGate()->getChannel()->par("distance");//Get assigned distance for each channel written in .ned file
               // this is the distance of the quantum channel and our routing metric

               int address = quantumTopo->getNode(x)->getModule()->par("address");
               EV<<"\n thisNode is "<< quantumTopo->getNode(x)->getModule()->getFullName() <<" has "<<channel_dist<<" km quantum channel distance\n";
               EV << "This node number is = "<<x<<"\n";
               EV << "This node address is = "<<address<<"\n";

               EV<<quantumTopo->getNode(x)->getLinkOut(j)->getLocalGate()->getFullName()<<"\n";


               if(strstr(quantumTopo->getNode(x)->getLinkOut(j)->getLocalGate()->getFullName(),"quantum")){
                   //Only include quantum link in quantum routing table
                   EV<<"\n Enable quantum from quantumTopo \n";
                   quantumTopo->getNode(x)->getLinkOut(j)->setWeight(channel_dist);//Set channel weight
                   EV<<"\n Including quantum channel link cost = "<< quantumTopo->getNode(x)->getLinkOut(j)->getWeight()<<": "<<quantumTopo->getNode(x)->getLinkOut(j)->getLocalGate()->getChannel()->getFullName()<<"\n";
               }else{
                   EV<<"\n Disable classical from quantumTopo \n";
                   quantumTopo->getNode(x)->getLinkOut(j)->disable();
               }
           }
       }
       EV<<"\nDone initializing cTopology for quantum link distances\n";
    
}

void Router::initNames() {
    for (int x = 0; x < quantumTopo->getNumNodes(); x++) {//Traverse through all nodes
        nnames[x] = quantumTopo->getNode(x)->getModule()->getFullName();
    }
}

void Router::printNames() {
    for (int x = 0; x < quantumTopo->getNumNodes(); x++) {//Traverse through all nodes
        EV << "\n";
    }
}

// given the end nodes on a link, get the weight of the link from the topology
double Router::getQDist(int src, int dest) {
    EV<<"Computing distance***\n";
    EV<<"Source: "<<quantumTopo->getNode(src)->getModule()->getFullName()<<"\n";
    EV<<"Destination name: "<<quantumTopo->getNode(src)->getLinkOut(dest)->getLocalGate()->getFullName()<<"\n";
    EV<<"Weight of link: "<< quantumTopo->getNode(src)->getLinkOut(dest)->getWeight()<<"\n";

    return quantumTopo->getNode(src)->getLinkOut(dest)->getWeight();
}

// populate a graph's edges
void Router::populateGraph() {
    /*
    EV<<"Populating the graph\n";
    for (int x = 0; x < quantumTopo->getNumNodes(); x++) {//Traverse through all nodes
        for (int y = 0; y < quantumTopo->getNode(x)->getNumOutLinks(); y++) {//Traverse through all edges
            if(x != y and (strstr(quantumTopo->getNode(x)->getLinkOut(y)->getLocalGate()->getFullName(),"quantum"))) {
                double weight = getQDist(x,y);
                EV << "Add edge from node "<<x<<" to node "<<y<<" with weight: "<<weight<<"\n";
                //g.addEdge(x, y, weight);
            }
        }
    }
    */
    //Topology creation for routing table
    EV <<"Trying to find QNodes...\n";
           cTopology *topo2 = new cTopology("topo2");
           cMsgPar *yes = new cMsgPar();
           yes->setStringValue("yes");
           topo2->extractByParameter("includeInTopo",yes->str().c_str());//Any node that has a parameter includeInTopo will be included in routing
           delete(yes);
           if(topo2->getNumNodes()==0 || topo2==nullptr){//If no node with the parameter & value found, do nothing.
                    return;
           }

           cTopology::Node *thisNode = topo2->getNodeFor(getParentModule());//The parent node with this specific router

           int number_of_links_total = 0;

           //Initialize channel weights for all existing links.
           for (int x = 0; x < topo2->getNumNodes(); x++) {//Traverse through all nodes
               //For Bidirectional channels, parameters are stored in LinkOut not LinkIn.
               for (int j = 0; j < topo2->getNode(x)->getNumOutLinks(); j++) {//Traverse through all links from a specific node.
                   //thisNode->disable();//You can also disable nodes or channels accordingly to represent broken hardwares
                   EV<<"\n thisNode is "<< topo2->getNode(x)->getModule()->getFullName() <<" has "<<topo2->getNode(x)->getNumOutLinks()<<" links \n";
                   double channel_dist = topo2->getNode(x)->getLinkOut(j)->getLocalGate()->getChannel()->par("distance");//Get assigned cost for each channel written in .ned file

                   /*
                   EV<<topo2->getNode(x)->getLinkOut(j)->getLocalGate()->getFullName()<<" =? "<<"includes quantum?"<<"\n";
                   //if(strcmp(topo->getNode(x)->getLinkOut(j)->getLocalGate()->getChannel()->getFullName(),"QuantumChannel")==0){
                   if(strstr(topo2->getNode(x)->getLinkOut(j)->getLocalGate()->getFullName(),"quantum")){
                       //Ignore quantum link in classical routing table
                       EV<<"\n Disable quantum from topo \n";
                       topo2->getNode(x)->getLinkOut(j)->disable();
                   }else{
                       //Otherwise, keep the classical channels and set the weight
                       topo2->getNode(x)->getLinkOut(j)->setWeight(channel_cost);//Set channel weight
                       EV<<"\n Including classical channel link cost = "<< topo->getNode(x)->getLinkOut(j)->getWeight()<<": "<<topo->getNode(x)->getLinkOut(j)->getLocalGate()->getChannel()->getFullName()<<"\n";
                   }*/
               }
           }
}

void Router::yensTest(){
    EV<<"fake yens test\n";

    // create the graph
        int V = 9;
        Graph g(V);
        // the picture of g is in the link of line 3
        // edge between u, v. The third int is weight
        g.addEdge(0, 1, 4);
        g.addEdge(0, 7, 8);
        g.addEdge(1, 2, 8);
        g.addEdge(1, 7, 11);
        g.addEdge(2, 3, 7);
        g.addEdge(2, 8, 2);
        g.addEdge(2, 5, 4);
        g.addEdge(3, 4, 9);
        g.addEdge(3, 5, 14);
        g.addEdge(4, 5, 10);
        g.addEdge(5, 6, 2);
        g.addEdge(6, 7, 1);
        g.addEdge(6, 8, 6);
        g.addEdge(7, 8, 7);

        vector<vector<int> > A;

        vector<int> temp = {0, 1, 2, 5, 6};

        for(auto it = temp.begin(); it != temp.end(); ++it)
                EV << *it << ' ';
        temp = slicing(temp, 0, 3);
        EV <<"\nSliced the vector from 0, 3\n";
        showlist(temp);
        // shortest path from node 0 to 4, K = 8

        EV <<"Calling Yens\n";
        A = yen(g, 0, 4, 8); // simulation crashed after inputting parameters here

        for(auto it = A.begin(); it != A.end(); ++it) {
            showlist(*it);
            //cout << "\n";
            EV << "\n";
        }

}

} // namespace modules
} // namespace quisp
