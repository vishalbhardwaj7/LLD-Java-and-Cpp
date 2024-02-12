// object identification
// 1. Internal Button
// 2. Door
// 3. ExternalButton
// 4. Floor
// 5. Elevtor Car - Display, Door, Floor, Status, Direction
// 6. Display


#include <bits/stdc++.h>
using namespace std;

enum Direction{
    UP,
    DOWN
};

enum Status{
    IDLE,
    MOVING
};

class Display{
    int currentFloor;
    Direction direction;
};

class ElevatorCar{ // Dumb object
    int id;
    Display display;
    InternalButton internalButton;
    int currentFloor;
    Door door;
public:
    void move(int floor, Direction direction){}// dumb function just ask it to move
};

class Floor{
    int id;
    InternalButton internalButton;
};

class ElevatorController{
    ElevatorCar elevatorCar;
    // Priority queues for logic all logic happens here
public:
    void acceptNewReq(Floor floor,Direction direction){
        // accep the req
    }

    controlElevatorCar(){
        // runs until killing of machine or electricity
    }
};

class Door{
    // has some functionality
};

class InternalButton{ // req can come from this button
    Floor floor;
    InternalButtonDispatcher dispatcher;
public:
    void submitReq(int liftId, int direction){
        // invoke the dispatcher ..    // dispatcher.submitReq()
    }
};

class InternalButtonDispatcher{
    ElevatorController* controller;
public:
    void submitReq(int liftId){// controller id){
        // controller.acceptNewReq;
    }
};

class ExternalButton{ // or request can come from this button
    Floor floor;
    ExternalButtonDispatcher dispatcher;
public:
    void submitReq(int liftId, int direction){
        // invoke the dispatcher ..    // dispatcher.submitReq()
    }
};

class ExternalButtonDispatcher{// 
    Floor id;
    vector<ElevatorController*> list;
public:
    void submitReq(int liftId){// controller id){
        // list[id].acceptNewReq()
    }

};


// -================ Strategy deisgn pattern useed
class LiftSelectionStrategy{
    // abstract class stragtegy
    virtual ElevatorController* getLift()=0;
};

class OddEvenStrategy{
// implements a function on lift and 
    ElevatorController* getLift(){
        // some logic
    }
};
class NearToFLoorSAtrategy: public LiftSelectionStrategy{
// implements a function on lift and 
    ElevatorController* getLift(){}
        // some logic mannnn    
};

class OddEvenDispatcher: public ExternalButtonDispatcher{
    // has a odd even strategy
// use a trategy odd even and have a set of number of lift to apply that algo too
// pass thwe strategy in constructor injection in run time

};
class NearToFloorDispatcher: public ExternalButtonDispatcher{
    // has 
// use a trategy near to floow and have a set of number of lift to apply that algo too
// pass thwe strategy in constructor injection in run time
};

class Floor{
    int floorId;
    ExternalButton ext;
};

class Building{
    vector<Floor*> floors;
    // each floor has a button
};

int main(){
    // logic can run here
}


// two types of algos will run one on elevatorController who will make use of one lift
// one on external dispatcher level to select which elevator controller to dispatch the request to