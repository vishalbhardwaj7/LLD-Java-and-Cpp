#include<bits/stdc++.h>
using namespace std;

// ------------- Problem ---------------

// class Vehicle{
// public:
//     bool getNumberOfTyres(){
//         return 2;//some functionality
//     }
//     bool isEngineOn(){
//         return true;
//     }
// };

// class Bike:public Vehicle{
// };

// class Car:public Vehicle{
// };

// class Bicycle:public Vehicle{//overrides the method of isEngineOn and returns a null value
//     bool isEngineOn(){
//         return NULL;
//     }
// };

// int main(){
//     cout << endl;
//     vector<Vehicle*> nums;
//     Vehicle *v1= new Bike();
//     Vehicle *v2= new Car();
//     Vehicle *v3= new Bicycle();
//     nums.push_back(v1);
//     nums.push_back(v2);
//     nums.push_back(v3);
//     for(auto &v:nums){
//         cout<<to_string(v->isEngineOn())<<endl;
//     }
// }

// Java will give null pointer exception while cpp gives this warning 

// main.cpp:24:16: warning: implicit conversion of NULL constant to 'bool' [-Wnull-conversion]
//        return NULL;
 //       ~~~~~~ ^~~~
 //              false

 // null is implicitly converted to bool false but still there is issuesss


// ------------- FIX ------------


class Vehicle{
public:
    bool getNumberOfTyres(){
        return 2;//some functionality
    }
    // bool isEngineOn(){ /// dont define this here if all immidaite child can not derive this
    //     return true;
    // }
};

class EngineVehicle: public Vehicle{
    bool isEngineOn(){
        return true;
    }
};

class Bike:public EngineVehicle{
};

class Car:public EngineVehicle{
};

class nonEngineVehicle: public Vehicle{
};

class Bicycle:public nonEngineVehicle{
};

// now just you can call number of tyres for all but engine is limited to children of engine vehicles...........