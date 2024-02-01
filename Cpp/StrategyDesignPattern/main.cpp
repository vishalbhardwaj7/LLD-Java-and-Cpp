#include<bits/stdc++.h>
using namespace std;

// ------------ Problem ----------

// class Vehicle{
//     public:
//     void drive(){
//         // some xyz
//     }
// };

// class OffRoadVehicle: public Vehicle{
//     public:
//     void drive(){
//         // some special implementation
//     }
// };

// class OffRoadVehicle: public Vehicle{
//     public:
//     void drive(){
//         // some special implementation different
//     }
// };

// So now the issues is that if there is a same drive logic used in these two children, then we need to duplicate the code


// ----------- FIX ---------------------
// MAke a strategy class and pass it across

class DrivingStrategy{
public: 
    virtual void drive(){ // giving this virtual keyword so that it can be overriden in child classes for achieiving run time binding or polymorphism
        cout<<"Normal Drive Strategy"<<endl;
    }
};
class OffRoadDrivingStrategy: public DrivingStrategy{
public:  // override the method from parent class
    void drive(){
        cout<<"Speed is slow in off road strategy"<<endl;
    }
};
class OnRoadDrivingStrategy: public DrivingStrategy{
public: 
    void drive(){
        cout<<"Speed is fast in on road strategy"<<endl;
    }
};

class Vehicle {
    DrivingStrategy* drivingStrategy; // use pointer

public:
    Vehicle(DrivingStrategy* strategy) { // initialize
        drivingStrategy = strategy;
    }
    void drive(){
        drivingStrategy->drive();
    }
};


class DirtBike: public Vehicle{
public:
    DirtBike(DrivingStrategy* strategy) : Vehicle(strategy) { // using super constructor i can just pass this to parent vehicle
        // Additional initialization for DirtBike if needed
    }
};
class Car: public Vehicle{
public:
    Car(DrivingStrategy* strategy) : Vehicle(strategy) {
    }

};
class Bike : public Vehicle{
public:
    Bike(DrivingStrategy* strategy) : Vehicle(strategy) {
    }
};

// also i can hardcode a vehicle to follow a decided strategy 
class Bike3 : public Vehicle{
public:
    Bike3() : Vehicle(new OnRoadDrivingStrategy()) {
    }
};

int main(){
    OffRoadDrivingStrategy *offRoadDrivingStrategy = new OffRoadDrivingStrategy();
    OnRoadDrivingStrategy onRoadDrivingStrategy;
    DirtBike* dirtBike = new DirtBike(offRoadDrivingStrategy); 
    Vehicle* bike3= new Bike3();

    dirtBike->drive();
    bike3->drive();
}
