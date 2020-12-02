import ned.DatarateChannel;
package networks;

//
// TODO auto-generated type
//
network Better_quantum_network
{
    parameters:
        **.Speed_of_light_in_fiber = 205336.986301 km;
        **.buffers = default(30);
        **.distance = 20 km;
        @display("bgb=800,400");
    types:
        channel C extends DatarateChannel
        {
            double cost = default(0);
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
        endnode0: QNode {
            address = 10000000+0;
            nodeType = "EndNode";
            @display("i=device/pc;p=29.145,210.045");
        }
        endnode1: QNode {
            address = 10000000+1;
            nodeType = "EndNode";
            @display("i=device/pc;p=334.665,36.18");
        }
        endnode2: QNode {
            address = 10000000+2;
            nodeType = "EndNode";
            @display("i=device/pc;p=738.675,191.955");
        }
        repeater0: QNode {
            address = 10000000+3;
            nodeType = "Repeater";
            @display("i=device/smallrouter;p=160.8,214.065");
        }
        repeater1: QNode {
            address = 10000000+4;
            nodeType = "Repeater";
            @display("i=device/smallrouter;p=172.86,355.77002");
        }
        repeater2: QNode {
            address = 10000000+5;
            nodeType = "Repeater";
            @display("i=device/smallrouter;p=344.715,149.745");
        }
        repeater3: QNode {
            address = 10000000+6;
            nodeType = "Repeater";
            @display("i=device/smallrouter;p=570.84,201");
        }
        repeater4: QNode {
            address = 10000000+7;
            nodeType = "Repeater";
            @display("i=device/smallrouter;p=578.88,344.715");
        }
        HoM0: HoM {
            address = 10000000+8;
            @display("i=device/bsm;p=96.48,240.195");
        }
        HoM1: HoM {
            address = 10000000+9;
            @display("i=device/bsm;p=95.475,300.495");
        }
        HoM2: HoM {
            address = 10000000+10;
            @display("i=device/bsm;p=154.77,280.39502");
        }
        HoM3: HoM {
            address = 10000000+11;
            @display("i=device/bsm;p=339.69,94.47");
        }
        HoM4: HoM {
            address = 10000000+12;
            @display("i=device/bsm;p=233.16,162.81");
        }
        HoM5: HoM {
            address = 10000000+13;
            @display("i=device/bsm;p=348.73502,202.005");
        }
        HoM6: HoM {
            address = 10000000+14;
            @display("i=device/bsm;p=221.1,239.19");
        }
        HoM7: HoM {
            address = 10000000+15;
            @display("i=device/bsm;p=226.125,299.49");
        }
        HoM8: HoM {
            address = 10000000+16;
            @display("i=device/bsm;p=359.79,350.745");
        }
        HoM9: HoM {
            address = 10000000+17;
            @display("i=device/bsm;p=353.76,262.305");
        }
        HoM10: HoM {
            address = 10000000+18;
            @display("i=device/bsm;p=462.30002,160.8");
        }
        HoM11: HoM {
            address = 10000000+19;
            @display("i=device/bsm;p=507.525,232.155");
        }
        HoM12: HoM {
            address = 10000000+20;
            @display("i=device/bsm;p=498.48,295.47");
        }
        HoM13: HoM {
            address = 10000000+21;
            @display("i=device/bsm;p=567.825,267.33002");
        }
        HoM14: HoM {
            address = 10000000+22;
            @display("i=device/bsm;p=669.33,216.075");
        }
        HoM15: HoM {
            address = 10000000+23;
            @display("i=device/bsm;p=674.355,291.45");
        }
        router0: QNode {
            address = 10000000+24;
            nodeType = "Router";
            @display("i=device/router;p=283.41,263.31");
        }
        router1: QNode {
            address = 10000000+25;
            nodeType = "Router";
            @display("i=device/router;p=426.12,260.295");
        }

    connections:
        //connect endnodes to repeaters
        endnode0.port++ <--> C {  cost = 20; } <--> HoM0.port++;
        HoM0.port++ <--> C <--> repeater0.port++;

        endnode0.port++ <--> C <--> HoM1.port++;
        HoM1.port++ <--> C <--> repeater1.port++;

        endnode1.port++ <--> C <--> HoM3.port++;
        HoM3.port++ <--> C <--> repeater2.port++;

        endnode2.port++ <--> C <--> HoM14.port++;
        HoM14.port++ <--> C <--> repeater3.port++;

        endnode2.port++ <--> C <--> HoM15.port++;
        HoM15.port++ <--> C <--> repeater4.port++;
        //connect repeaters to each other and routers
        repeater0.port++ <--> C <--> HoM2.port++;
        HoM2.port++ <--> C <--> repeater1.port++;

        repeater0.port++ <--> C <--> HoM6.port++;
        HoM6.port++ <--> C <--> router0.port++;

        repeater1.port++ <--> C <--> HoM7.port++;
        HoM7.port++ <--> C <--> router0.port++;

        repeater1.port++ <--> C <--> HoM8.port++;
        HoM8.port++ <--> C <--> repeater4.port++;

        repeater2.port++ <--> C <--> HoM4.port++;
        HoM4.port++ <--> C <--> repeater0.port++;

        repeater2.port++ <--> C <--> HoM10.port++;
        HoM10.port++ <--> C <--> repeater3.port++;

        repeater3.port++ <--> C <--> HoM13.port++;
        HoM13.port++ <--> C <--> repeater4.port++;

        repeater3.port++ <--> C <--> HoM5.port++;
        HoM5.port++ <--> C <--> repeater0.port++;

        repeater3.port++ <--> C <--> HoM11.port++;
        HoM11.port++ <--> C <--> router1.port++;

        repeater4.port++ <--> C <--> HoM12.port++;
        HoM12.port++ <--> C <--> router1.port++;
        //router to router
        router0.port++ <--> C <--> HoM9.port++;
        HoM9.port++ <--> C <--> router1.port++;

        //connect endnodes to repeaters
        endnode0.quantum_port++ <--> QuantumChannel <--> HoM0.quantum_port++;
        HoM0.quantum_port++ <--> QuantumChannel <--> repeater0.quantum_port++;

        endnode0.quantum_port++ <--> QuantumChannel <--> HoM1.quantum_port++;
        HoM1.quantum_port++ <--> QuantumChannel <--> repeater1.quantum_port++;

        endnode1.quantum_port++ <--> QuantumChannel <--> HoM3.quantum_port++;
        HoM3.quantum_port++ <--> QuantumChannel <--> repeater2.quantum_port++;

        endnode2.quantum_port++ <--> QuantumChannel <--> HoM14.quantum_port++;
        HoM14.quantum_port++ <--> QuantumChannel <--> repeater3.quantum_port++;

        endnode2.quantum_port++ <--> QuantumChannel <--> HoM15.quantum_port++;
        HoM15.quantum_port++ <--> QuantumChannel <--> repeater4.quantum_port++;
        //connect repeaters to each other and routers
        repeater0.quantum_port++ <--> QuantumChannel <--> HoM2.quantum_port++;
        HoM2.quantum_port++ <--> QuantumChannel <--> repeater1.quantum_port++;

        repeater0.quantum_port++ <--> QuantumChannel <--> HoM6.quantum_port++;
        HoM6.quantum_port++ <--> QuantumChannel <--> router0.quantum_port++;

        repeater1.quantum_port++ <--> QuantumChannel <--> HoM7.quantum_port++;
        HoM7.quantum_port++ <--> QuantumChannel <--> router0.quantum_port++;

        repeater1.quantum_port++ <--> QuantumChannel <--> HoM8.quantum_port++;
        HoM8.quantum_port++ <--> QuantumChannel <--> repeater4.quantum_port++;

        repeater2.quantum_port++ <--> QuantumChannel <--> HoM4.quantum_port++;
        HoM4.quantum_port++ <--> QuantumChannel <--> repeater0.quantum_port++;

        repeater2.quantum_port++ <--> QuantumChannel <--> HoM10.quantum_port++;
        HoM10.quantum_port++ <--> QuantumChannel <--> repeater3.quantum_port++;

        repeater3.quantum_port++ <--> QuantumChannel <--> HoM13.quantum_port++;
        HoM13.quantum_port++ <--> QuantumChannel <--> repeater4.quantum_port++;

        repeater3.quantum_port++ <--> QuantumChannel <--> HoM5.quantum_port++;
        HoM5.quantum_port++ <--> QuantumChannel <--> repeater0.quantum_port++;

        repeater3.quantum_port++ <--> QuantumChannel <--> HoM11.quantum_port++;
        HoM11.quantum_port++ <--> QuantumChannel <--> router1.quantum_port++;

        repeater4.quantum_port++ <--> QuantumChannel <--> HoM12.quantum_port++;
        HoM12.quantum_port++ <--> QuantumChannel <--> router1.quantum_port++;
        //router to router
        router0.quantum_port++ <--> QuantumChannel <--> HoM9.quantum_port++;
        HoM9.quantum_port++ <--> QuantumChannel <--> router1.quantum_port++;

}
