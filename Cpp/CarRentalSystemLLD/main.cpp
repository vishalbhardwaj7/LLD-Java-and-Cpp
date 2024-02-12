#include<bits/stdc++.h>
using namespace std;

class Store{
    VehicleInventoryManagement inventoryManager;
    vector<Reservation*> reservationList;
public:
    // return vehiicles on basis of filters
    vector<Vehicle*> getVehicle(VehicleType type){
        inventoryManager.getVehicle(type);//we can overload this 
    }
    // complete reswervation 
    bool completeReseevation(){
        // invoke the complete reservation
    }
    // createReservation
    // take all things and pass to create Reservation function of reservation class to create reservation
    // list.add(reservation returned from create reservation)
};

class VehicleInventoryManagement{
    vector<Vehicle> vehicle;
    //crud operations on vehicles
    // get vehicles
    // deletevehicle
    // put vehicles
    // updatevehicle
};

// car inventory manager and bike............

class Vehicle{
    VehicleType vehicleType;
    Date manFactureDate;
    int kmsDriven;
    int dailyCost;
    int monthlyCos;
};

class Date{
    byte month,day,year;
};
enum VehicleType{
    CAR,
    BIKE
};

class Car: public Vehicle{

};

class Reservation{
    Vehicle vehicle;
    User user;
    string pickUp;
    Location location;
    string drop;
    Date bookedFrom;
    Date bookedTo;

    // create reservation

    // take a user, location and other things an create a reservartion for that vehicle and return an object

    // update reservation

    // complete reservation....... 
};

class User{
    name, driving licesnce ; id
};

class location{
///// add some random shit
};


clas Bill{
    bool isPaid;
    doubleAmount;

    // generate the bill 
}

class Payment{
    paybill(bill);
}

class VehicleRentalSystem{
    vector<User*> users;
    vector<Store*> stores;

//crud operaiton
// remove users
// add users
// add stores
// remove stores
// get store
};



int main(){
    // create a vector of users
    // crearte a vector of stores
    // create a list of vehicles
    // make a vehicle rental system
    VehicleRentalSystem *vrs = new VehicleRentalSystem(stoes,users);

    //1. user comes
    User user = vrs->getUsr(0);

    //2. fetch current locaiton

    Store store= vrs->getStore(location);

    //3. get all vehicle from thaty stor

    vector<vehicle> storeVehicles = store.getVehicles(Car);

    //4. reserve your car

    Reservation reservation = store.createReservation(.......... pass all details);

    //5. Geneate bill

    Bill bill = new Bill(reservation);

    // 6. Paymemnt

    Payment payment= new Payment();
    payment.payBill(reservation);

    // compleye reservation


    store.completeReseevation(servation, id, payment);
}