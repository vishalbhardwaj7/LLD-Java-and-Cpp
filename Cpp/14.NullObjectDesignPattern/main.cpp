#include<bits/stdc++.h>
using namespace std;

class Vehicle{
public:
    virtual int getSeatingCapacity() = 0;
    virtual int getSpeed() = 0;
};

class NullVehicle : public Vehicle{
public:
    int getSeatingCapacity(){
        return 0;//some default behivour
    }
    int getSpeed(){
        return 0;// default behavior
    }
};

class Car: public Vehicle{
public:
    int getSeatingCapacity(){
        return 5;
    }
    int getSpeed(){
        return 100;
    }
};

// make a factory

class VehicleFactory{
public:
    Vehicle * makeVehicle(string input){
        if(input=="CAR")
            return new Car();
        else return new NullVehicle();
    }
};

int main(){
    VehicleFactory* factory = new VehicleFactory();

    Vehicle * bike = factory->makeVehicle("BIKE");//it wil lreturn null vehicle object

    cout << bike->getSeatingCapacity()<<endl;// should print 0
}

