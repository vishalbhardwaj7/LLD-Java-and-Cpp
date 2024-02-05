#include <bits/stdc++.h>
using namespace std;

// - Basically, it is a factory of factories............

// A one more layer above the factory design pattern

class Vehicle{//abstract class vehicle
    public:
    virtual void print ()=0;
};

class Maruti: public Vehicle{
public:
    void print(){
        cout<< "This is Maruti which is Normal vehicle"<<endl;
    }
};
class Nano: public Vehicle{
public:
    void print(){
        cout<< "This is Nano which is Normal vehicle"<<endl;
    }
};
class Swift: public Vehicle{
public:
    void print(){
        cout<< "This is Swift which is Normal vehicle"<<endl;
    }
};
class Bmw: public Vehicle{
public:
    void print(){
        cout<< "This is BMW which is Luxury vehicle"<<endl;
    }
};
class Mercedes: public Vehicle{
public:
    void print(){
        cout<< "This is Mercedes which is Luxury vehicle"<<endl;
    }
};

// two factories


class VehicleFactory{
public:
    virtual Vehicle* getVehicle(string vehicle)=0;
};

class NormalVehicleFactory: public VehicleFactory{
public:
    Vehicle* getVehicle(string vehicle){
        if(vehicle=="MARUTI")
            return new Maruti();
        if(vehicle=="NANO")
            return new Nano();
        if(vehicle=="SWIFT")
            return new Swift();
        throw runtime_error("Please provide a valid NormalVehicle Requirement");
    }
};

class LuxuryVehicleFactory: public VehicleFactory{
public:
    Vehicle* getVehicle(string vehicle){
        if(vehicle=="BMW")
            return new Bmw();
        if(vehicle=="MERCEDES")
            return new Mercedes();
        throw runtime_error("Please provide a valid LuxuryVehicle Requirement");
    }
};

// now we need a factory on top of this vehicle factory 

class VehicleFactoryGenerator{
public:
    VehicleFactory* getVehicleFactory(string vehicleFactory){
        if(vehicleFactory=="LUXURY")
            return new LuxuryVehicleFactory();
        if(vehicleFactory=="NORMAL")
            return new NormalVehicleFactory();
        throw runtime_error("Please provide a valid vehicle factory type");
    }
};

int main(){
    // lets say i want a maruti car

    try{
        VehicleFactoryGenerator *vehicleFactoryGenerator = new VehicleFactoryGenerator();


        VehicleFactory *vehicleFactory1 = vehicleFactoryGenerator->getVehicleFactory("LUXURY");
        VehicleFactory *vehicleFactory2 = vehicleFactoryGenerator->getVehicleFactory("NORMAL");

        // Vehicle* maruti = vehicleFactory1->getVehicle("BMW");
        Vehicle* maruti = vehicleFactory2->getVehicle("MARUTI");

        maruti->print();
    }
    catch(exception &e){
        // cout<< "Caught an exception";
        cout << e.what()<<endl;
    }



}