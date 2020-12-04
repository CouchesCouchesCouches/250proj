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
        //**.distance = 20 km;
        @display("bgb=1000,600");
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
            //double distance @unit(km) = default(20km);
            double distance @unit(km) = uniform(2km, 20km);
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
            @display("i=device/pc;p=48.3405,356.6745");
        }
        endnode1: QNode {
            address = 10000000+1;
            nodeType = "EndNode";
            @display("i=device/pc;p=350.142,30.0495");
        }
        endnode2: QNode {
            address = 10000000+2;
            nodeType = "EndNode";
            @display("i=device/pc;p=953.745,305.721");
        }
        repeater0: QNode {
            address = 10000000+10;
            nodeType = "Repeater";
            @display("i=device/smallrouter;p=185.523,237.783");
        }
        repeater1: QNode {
            address = 10000000+20;
            nodeType = "Repeater";
            @display("i=device/smallrouter;p=210.3465,522.6");
        }
        repeater2: QNode {
            address = 10000000+30;
            nodeType = "Repeater";
            @display("i=device/smallrouter;p=472.953,118.8915");
        }
        repeater3: QNode {
            address = 10000000+40;
            nodeType = "Repeater";
            @display("i=device/smallrouter;p=773.448,222.105");
        }
        repeater4: QNode {
            address = 10000000+50;
            nodeType = "Repeater";
            @display("i=device/smallrouter;p=800.8845,514.761");
        }
        repeater5: QNode {
            address = 10000000+60;
            nodeType = "Repeater";
            @display("i=device/smallrouter;p=484.7115,263.913");
        }
        repeater6: QNode {
            address = 10000000+70;
            nodeType = "Repeater";
            @display("i=device/smallrouter;p=488.631,531.7455");
        }
        HoM0: HoM {
            address = 10000000+100;
            @display("i=device/bsm;p=105.8265,273.0585");
        }
        HoM1: HoM {
            address = 10000000+101;
            @display("i=device/bsm;p=124.1175,446.823");
        }
        HoM2: HoM {
            address = 10000000+102;
            @display("i=device/bsm;p=193.362,356.6745");
        }
        HoM3: HoM {
            address = 10000000+103;
            @display("i=device/bsm;p=472.953,30.0495");
        }
        HoM4: HoM {
            address = 10000000+104;
            @display("i=device/bsm;p=312.2535,151.554");
        }
        HoM5: HoM {
            address = 10000000+105;
            @display("i=device/bsm;p=350.142,231.2505");
        }
        HoM6: HoM {
            address = 10000000+106;
            @display("i=device/bsm;p=271.752,290.043");
        }
        HoM7: HoM {
            address = 10000000+107;
            @display("i=device/bsm;p=271.752,437.6775");
        }
        HoM8: HoM {
            address = 10000000+108;
            @display("i=device/bsm;p=322.7055,523.9065");
        }
        HoM9: HoM {
            address = 10000000+109;
            @display("i=device/bsm;p=488.631,395.8695");
        }
        HoM10: HoM {
            address = 10000000+110;
            @display("i=device/bsm;p=641.4915,151.554");
        }
        HoM11: HoM {
            address = 10000000+111;
            @display("i=device/bsm;p=692.445,282.204");
        }
        HoM12: HoM {
            address = 10000000+112;
            @display("i=device/bsm;p=692.445,455.9685");
        }
        HoM13: HoM {
            address = 10000000+113;
            @display("i=device/bsm;p=783.9,356.6745");
        }
        HoM14: HoM {
            address = 10000000+114;
            @display("i=device/bsm;p=868.8225,246.9285");
        }
        HoM15: HoM {
            address = 10000000+115;
            @display("i=device/bsm;p=880.581,424.6125");
        }
        HoM16: HoM {
            address = 10000000+116;
            @display("i=device/bsm;p=484.7115,192.0555");
        }
        HoM17: HoM {
            address = 10000000+117;
            @display("i=device/bsm;p=617.9745,231.2505");
        }
        HoM18: HoM {
            address = 10000000+118;
            @display("i=device/bsm;p=382.8045,322.7055");
        }
        HoM19: HoM {
            address = 10000000+119;
            @display("i=device/bsm;p=567.021,305.721");
        }
        HoM20: HoM {
            address = 10000000+120;
            @display("i=device/bsm;p=410.241,455.9685");
        }
        HoM21: HoM {
            address = 10000000+121;
            @display("i=device/bsm;p=567.021,446.823");
        }
        HoM22: HoM {
            address = 10000000+122;
            @display("i=device/bsm;p=632.346,523.9065");
        }

        router0: QNode {
            address = 10000000+1000;
            nodeType = "Router";
            @display("i=device/router;p=350.142,395.8695");
        }
        router1: QNode {
            address = 10000000+2000;
            nodeType = "Router";
            @display("i=device/router;p=632.346,373.659");
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

        repeater2.port++ <--> C <--> HoM4.port++;
        HoM4.port++ <--> C <--> repeater0.port++;

        repeater2.port++ <--> C <--> HoM10.port++;
        HoM10.port++ <--> C <--> repeater3.port++;

        repeater3.port++ <--> C <--> HoM13.port++;
        HoM13.port++ <--> C <--> repeater4.port++;

        repeater3.port++ <--> C <--> HoM11.port++;
        HoM11.port++ <--> C <--> router1.port++;

        repeater4.port++ <--> C <--> HoM12.port++;
        HoM12.port++ <--> C <--> router1.port++;
        //router to router
        router0.port++ <--> C <--> HoM9.port++;
        HoM9.port++ <--> C <--> router1.port++;

        //NEW REPEATER ROUTES
        repeater0.port++ <--> C <--> HoM5.port++;
        HoM5.port++ <--> C <--> repeater5.port++;

        repeater2.port++ <--> C <--> HoM16.port++;
        HoM16.port++ <--> C <--> repeater5.port++;

        repeater3.port++ <--> C <--> HoM17.port++;
        HoM17.port++ <--> C <--> repeater5.port++;

        repeater5.port++ <--> C <--> HoM18.port++;
        HoM18.port++ <--> C <--> router0.port++;

        repeater5.port++ <--> C <--> HoM19.port++;
        HoM19.port++ <--> C <--> router1.port++;

        repeater1.port++ <--> C <--> HoM8.port++;
        HoM8.port++ <--> C <--> repeater6.port++;

        repeater4.port++ <--> C <--> HoM22.port++;
        HoM22.port++ <--> C <--> repeater6.port++;

        repeater6.port++ <--> C <--> HoM20.port++;
        HoM20.port++ <--> C <--> router0.port++;

        repeater6.port++ <--> C <--> HoM21.port++;
        HoM21.port++ <--> C <--> router1.port++;



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

        repeater2.quantum_port++ <--> QuantumChannel <--> HoM4.quantum_port++;
        HoM4.quantum_port++ <--> QuantumChannel <--> repeater0.quantum_port++;

        repeater2.quantum_port++ <--> QuantumChannel <--> HoM10.quantum_port++;
        HoM10.quantum_port++ <--> QuantumChannel <--> repeater3.quantum_port++;

        repeater3.quantum_port++ <--> QuantumChannel <--> HoM13.quantum_port++;
        HoM13.quantum_port++ <--> QuantumChannel <--> repeater4.quantum_port++;

        repeater3.quantum_port++ <--> QuantumChannel <--> HoM11.quantum_port++;
        HoM11.quantum_port++ <--> QuantumChannel <--> router1.quantum_port++;

        repeater4.quantum_port++ <--> QuantumChannel <--> HoM12.quantum_port++;
        HoM12.quantum_port++ <--> QuantumChannel <--> router1.quantum_port++;
        //router to router
        router0.quantum_port++ <--> QuantumChannel <--> HoM9.quantum_port++;
        HoM9.quantum_port++ <--> QuantumChannel <--> router1.quantum_port++;

        //NEW ROUTES
        repeater0.quantum_port++ <--> QuantumChannel <--> HoM5.quantum_port++;
        HoM5.quantum_port++ <--> QuantumChannel <--> repeater5.quantum_port++;

        repeater2.quantum_port++ <--> QuantumChannel <--> HoM16.quantum_port++;
        HoM16.quantum_port++ <--> QuantumChannel <--> repeater5.quantum_port++;

        repeater3.quantum_port++ <--> QuantumChannel <--> HoM17.quantum_port++;
        HoM17.quantum_port++ <--> QuantumChannel <--> repeater5.quantum_port++;

        repeater5.quantum_port++ <--> QuantumChannel <--> HoM18.quantum_port++;
        HoM18.quantum_port++ <--> QuantumChannel <--> router0.quantum_port++;

        repeater5.quantum_port++ <--> QuantumChannel <--> HoM19.quantum_port++;
        HoM19.quantum_port++ <--> QuantumChannel <--> router1.quantum_port++;

        repeater1.quantum_port++ <--> QuantumChannel <--> HoM8.quantum_port++;
        HoM8.quantum_port++ <--> QuantumChannel <--> repeater6.quantum_port++;

        repeater4.quantum_port++ <--> QuantumChannel <--> HoM22.quantum_port++;
        HoM22.quantum_port++ <--> QuantumChannel <--> repeater6.quantum_port++;

        repeater6.quantum_port++ <--> QuantumChannel <--> HoM20.quantum_port++;
        HoM20.quantum_port++ <--> QuantumChannel <--> router0.quantum_port++;

        repeater6.quantum_port++ <--> QuantumChannel <--> HoM21.quantum_port++;
        HoM21.quantum_port++ <--> QuantumChannel <--> router1.quantum_port++;

}
