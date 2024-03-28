#include<bits/stdc++.h>
using namespace std;

class BreatheImplementor{
public:
    virtual void breathe()=0;
};

class GillsBreatheImplementor: public BreatheImplementor{
public:
    void breathe(){
        cout<<"Breathing through gills";
    }
};
class LungsBreathe: public BreatheImplementor{
public:
    void breathe(){
        cout<<"Breathing through lungs";
    }
};


class LivingThings{
public:
    BreatheImplementor *breatheImplementorObj;
    LivingThings (BreatheImplementor *breatheImplementorObj):breatheImplementorObj(breatheImplementorObj){ }
    virtual void breatheProcess()=0;// virtual funciton
};

class Dog: public LivingThings{
public:
    Dog(BreatheImplementor *breatheImplementorObj):LivingThings(breatheImplementorObj){}
    void breatheProcess(){
        breatheImplementorObj->breathe();
    }
};
class Fish: public LivingThings{
public:
    Fish(BreatheImplementor *breatheImplementorObj):LivingThings(breatheImplementorObj){}
    void breatheProcess(){
        breatheImplementorObj->breathe();
    }
};
class Bird: public LivingThings{
public:
    Bird(BreatheImplementor *breatheImplementorObj):LivingThings(breatheImplementorObj){}
    void breatheProcess(){
        breatheImplementorObj->breathe();
    }
};



int main(){
    Dog * dog= new Dog(new LungsBreathe());
    dog->breatheProcess();
}