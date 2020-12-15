import ned.DatarateChannel;
package networks;

//
// TODO auto-generated type
//
network Simple_constant_quantum_cost
{
    parameters:
        **.Speed_of_light_in_fiber = 205336.986301 km;
        **.buffers = default(30);
        **.distance = 20 km;
        @display("bgb=746,327");
    types:
        channel C extends DatarateChannel
        {
            double cost = default(1);
            double distance @unit(km) = default(20km);
            //double distance @unit(km) = uniform(1km, 20km);
            //delay = uniform(0.01ms, 1s);
            double distance_of_light_in_fiber_per_sec @unit(km) = default(205336.986301km);
            delay = this.distance / distance_of_light_in_fiber_per_sec * 1s;
            datarate = uniform(1kbps, 100kbps);
            int test = default(0);
        }
        channel QuantumChannel extends DatarateChannel //ADD IN QUANTUMCHANNEL EXTENDSION??
        {
            double cost = default(1);
            double distance @unit(km) = default(20km);
            //delay = uniform(0.01ms, 1s);
            double distance_of_light_in_fiber_per_sec @unit(km) = default(205336.986301km);
            delay = this.distance / distance_of_light_in_fiber_per_sec * 1s;
            datarate = uniform(1kbps, 100kbps);
            double photon_loss_rate = default(0);//per km
            double channel_error_rate = default(0);//per km
            double Z_error_ratio = default(1);
            double X_error_ratio = default(1);
            double Y_error_ratio = default(1);
            int test = default(0);
        }

    submodules:
        endnode[8]: QNode {
            address = 10000000+index;
            nodeType = "EndNode";
            @display("i=device/pc;");
        }
        repeater[8]: QNode {
            address = sizeof(endnode) + index;
            nodeType = "Repeater";
            @display("i=device/smallrouter");
        }
        HoM[16]: HoM {
            address = sizeof(endnode) +sizeof(repeater) + index;
            @display("i=device/bsm;");
        }
        router[1]: QNode {
            address = sizeof(endnode) +sizeof(repeater) +sizeof(HoM) + index;
            nodeType = "Router";
            @display("i=device/router;");
        }
    connections:
        endnode[0].port++ <--> C {  cost = 20; } <--> HoM[0].port++;
        HoM[0].port++ <--> C <--> repeater[0].port++;
        repeater[0].port++ <--> C <--> HoM[1].port++;
        HoM[1].port++ <--> C <--> router[0].port++;

        endnode[1].port++ <--> C <--> HoM[2].port++;
        HoM[2].port++ <--> C <--> repeater[1].port++;
        repeater[1].port++ <--> C <--> HoM[3].port++;
        HoM[3].port++ <--> C <--> router[0].port++;

        endnode[2].port++ <--> C <--> HoM[4].port++;
        HoM[4].port++ <--> C <--> repeater[2].port++;
        repeater[2].port++ <--> C <--> HoM[5].port++;
        HoM[5].port++ <--> C <--> router[0].port++;

        endnode[0].quantum_port++ <--> QuantumChannel <--> HoM[0].quantum_port++;
        HoM[0].quantum_port++ <--> QuantumChannel <--> repeater[0].quantum_port++;
        repeater[0].quantum_port++ <--> QuantumChannel <--> HoM[1].quantum_port++;
        HoM[1].quantum_port++ <--> QuantumChannel <--> router[0].quantum_port++;

        endnode[1].quantum_port++ <--> QuantumChannel <--> HoM[2].quantum_port++;
        HoM[2].quantum_port++ <--> QuantumChannel <--> repeater[1].quantum_port++;
        repeater[1].quantum_port++ <--> QuantumChannel <--> HoM[3].quantum_port++;
        HoM[3].quantum_port++ <--> QuantumChannel <--> router[0].quantum_port++;

        endnode[2].quantum_port++ <--> QuantumChannel <--> HoM[4].quantum_port++;
        HoM[4].quantum_port++ <--> QuantumChannel <--> repeater[2].quantum_port++;
        repeater[2].quantum_port++ <--> QuantumChannel <--> HoM[5].quantum_port++;
        HoM[5].quantum_port++ <--> QuantumChannel <--> router[0].quantum_port++;
        
        endnode[3].port++ <--> C <--> HoM[6].port++;
        HoM[6].port++ <--> C <--> repeater[3].port++;
        repeater[3].port++ <--> C <--> HoM[7].port++;
        HoM[7].port++ <--> C <--> router[0].port++;

        endnode[4].port++ <--> C <--> HoM[8].port++;
        HoM[8].port++ <--> C <--> repeater[4].port++;
        repeater[4].port++ <--> C <--> HoM[9].port++;
        HoM[9].port++ <--> C <--> router[0].port++;

        endnode[5].port++ <--> C <--> HoM[10].port++;
        HoM[10].port++ <--> C <--> repeater[5].port++;
        repeater[5].port++ <--> C <--> HoM[11].port++;
        HoM[11].port++ <--> C <--> router[0].port++;
        
        endnode[6].port++ <--> C <--> HoM[12].port++;
        HoM[12].port++ <--> C <--> repeater[6].port++;
        repeater[6].port++ <--> C <--> HoM[13].port++;
        HoM[13].port++ <--> C <--> router[0].port++;

        endnode[7].port++ <--> C <--> HoM[14].port++;
        HoM[14].port++ <--> C <--> repeater[7].port++;
        repeater[7].port++ <--> C <--> HoM[15].port++;
        HoM[15].port++ <--> C <--> router[0].port++;

        endnode[3].quantum_port++ <--> QuantumChannel <--> HoM[6].quantum_port++;
        HoM[6].quantum_port++ <--> QuantumChannel <--> repeater[3].quantum_port++;
        repeater[3].quantum_port++ <--> QuantumChannel <--> HoM[7].quantum_port++;
        HoM[7].quantum_port++ <--> QuantumChannel <--> router[0].quantum_port++;

        endnode[4].quantum_port++ <--> QuantumChannel <--> HoM[8].quantum_port++;
        HoM[8].quantum_port++ <--> QuantumChannel <--> repeater[4].quantum_port++;
        repeater[4].quantum_port++ <--> QuantumChannel <--> HoM[9].quantum_port++;
        HoM[9].quantum_port++ <--> QuantumChannel <--> router[0].quantum_port++;

        endnode[5].quantum_port++ <--> QuantumChannel <--> HoM[10].quantum_port++;
        HoM[10].quantum_port++ <--> QuantumChannel <--> repeater[5].quantum_port++;
        repeater[5].quantum_port++ <--> QuantumChannel <--> HoM[11].quantum_port++;
        HoM[11].quantum_port++ <--> QuantumChannel <--> router[0].quantum_port++;

        endnode[6].quantum_port++ <--> QuantumChannel <--> HoM[12].quantum_port++;
        HoM[12].quantum_port++ <--> QuantumChannel <--> repeater[6].quantum_port++;
        repeater[6].quantum_port++ <--> QuantumChannel <--> HoM[13].quantum_port++;
        HoM[13].quantum_port++ <--> QuantumChannel <--> router[0].quantum_port++;

        endnode[7].quantum_port++ <--> QuantumChannel <--> HoM[14].quantum_port++;
        HoM[14].quantum_port++ <--> QuantumChannel <--> repeater[7].quantum_port++;
        repeater[7].quantum_port++ <--> QuantumChannel <--> HoM[15].quantum_port++;
        HoM[15].quantum_port++ <--> QuantumChannel <--> router[0].quantum_port++;

}
