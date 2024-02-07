#include <bits/stdc++.h>
using namespace std;

class ParkingSpot{
    int id;
    bool isEmpty;
    Vehicle vehicle; // has-a vehicle
public:
    void parkVehicle(Vehicle v){
        vehicle=v;
        isEmpty=false;
    }

    void removeVehicle(){
        vehicle = NULL;
        isEmpty-true;
    }
};

class twoWheelerSpot: public ParkingSpot{
public: 
    int price(){
        return 100;
    }
};
class fourWheelerSpot: public ParkingSpot{
public: 
    int price(){
        return 170;
    }
};

class ParkingSpotManager{ // will take care of all functions related to adding removing parking spaces and also removing adding the vehicles from them
    vector<ParkingSpot> parkingSpots;
    ParkingStrategy *parkingStrategy;// strategy design pattern where we can find parking spaces according to the strategies 

public:
    ParkingSpotManager(int size, ParkingStrategy *parkingStrategy):parkingStrategy(parkingStrategy){
        parkingSpots.resize(size);
    }
    pair<bool,int> findParkingSpace(){
        // on basis of the parking strategy it will possess the logic to find the parking space
        // so if it just returns a true and a index of parking spot 
    }

    void addParkingSpace(){
        // it can increase vector's length
    }

    void removeParkingSpace(){
        // it can remove a parking space 
    }

    void parkVehicle(Vehicle &v){
        // lets say find findParkingSpace returns some thing so it just calls that function
        auto res = findParkingSpace();
        if(res.first==true){
            parkingSpots[res.second].parkVehicle(v);
        }
        else    
        //handle this 
        
    }

    void removeVehicle(// take a parking spo){
        // call parking spot.removeVehicle
    //}
};

class TwoWheelerManager:public ParkingSpotManager{ // is-a psm or parking spot manager
    // vector<ParkingSpot> parkingSpots;// 600 parking spots // it can be dynamic too

public:
    TwoWheelerManager():ParkingSpotManager(600,new NearToEntranceStrategy()){
        
    }
};
class FourWheelerManager:public ParkingSpotManager{ // is-a psm or parking spot manager
    // vector<ParkingSpot> parkingSpots;// 600 parking spots // it can be dynamic too

public:
    FourWheelerManager():ParkingSpotManager(600,new NearToElevatorStrategy()){
        
    }
};

class ParkingStrategy{
    
};

class NearToEntranceStrategy:public ParkingStrategy{
//own logics
};
class NearToElevatorStrategy:public ParkingStrategy{
// own logics
};

enum VehicleType{
    TWOWHEELER,
    FOURWHEELER
};
class Vehicle{
    int vehicleNo;
    VehicleType vehicleType;
};


class Ticket{//
    long entryTime;
    Vehicle v;
    ParkingSpot ps;// so at time of exit the person will give ticket and we will identify the parking spot from it and ten call remove vehicle funciton
};



class EntranceGate{// this is not a driver function
// has a parking spot manager factory obect
// initialize that object

// according to type of vehicle we would need to get the desired parsking spot manager i mean how do we know what kind of manager is needed
 ParkingSpotManagerFactory psmf;
 ParkingSpotManager psm;// got from the factory
 Ticket obj;// ticket generation will happen here

 // ufnction


 findParkingSpace(){
    // pass the entrance gate number to find correct parking space for the strategy we used above

 }
 bookSpot(){
    // calls psm to park vehicle function
 }

 generatTicket(){
    //assign entry tiyme and the PS returned from the book spot function
 }
};

class ParkingSpotManagerFactory{
    TwoWheelerManager *twoWheelerManager;
    FourWheelerManager *fourWheelerManager;
public:
ParkingSpotManager* getParkingSpotManager(VehicleType vt) {
    switch case on VT and return the desired object
}
};

// exit gate logic

PricingStrategy{
    price(){
        return 100;
    }
}

HourlyBasis : public PricingStrategy{
    price(){// override the price function
        // get ps spot from ticket
        // ps.price*(currentTime-ticket.entrytime/60) // some logic like this
        // or some other logic
    }
};
MinuteBasis : public PricingStrategy{
    price(){// override the price function
        // get ps spot from ticket
        // ps.price*(currentTime-ticket.entrytime) // some logic like this
        // or some other logic
    }
};


// cost compute class

class CostComputation{
    // has a pricing strategy
    PricingStrategy *ps;

public:
    CostComputation(PricingStrategy *ps):ps(ps){
        // other initialization
    }

    // compute method
    {
        invoke psObject.price(ticket);// pass ticket to pricing strategy
    }
};

class TwoWheelerCostComputation : public CostComputation{
public:
    TwoWheelerCostComputation:CostComputation(new HourlyBasis() ){

    }
};
class FourWheelerCostComputationL: public CostComputation{
public:
    FourWheelerCostComputationL():CostComputation(new MinuteBasis() ){

    }
};

// eixt gate

class Exit{
    Ticket t;
    CostComputation ccObj;
    // bases on object given by factory we can get cost computation obj from factory as well
    // call price method of ccobj

    // we can also have a payment object

    // now we need a psm object to 
    // first use factory to get the psm object

    // now invoke remove vehicle function of that object
};


CostComputationFactory{ // to be done
    Ticket(){
        //take vehicletype from ticket
        switch on vehicle type and return two wheeler or 4 wheeler CostComputation object type
    }
}

Payment{
    
}
CashPayment
{
    //do entry in cash table
} 
CardPayment is-a-> Payment
{
    //do entry in card table.


}


//lets say if more than one Entrance is needed
// so we can have concept of entrance gate manager as i am already taking in consideration of the entrance type in finding the spots


// main flow {
    // make a entrance gate
    //  ParkingSpotManagerFactory psmf;
    // then call the psm object got from psmfactory function
    // then call the park vehicle function
    // then generate a ticket

    // now when exit comes we need a exit gate object too
    // now in exit gate give the ticket to that// 
    // call cost compute
    // then take payment
    // now when payment returns true
    // the just free the spotttt
}