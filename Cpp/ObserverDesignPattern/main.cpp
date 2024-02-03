#include<bits/stdc++.h>
using namespace std;


// =========== Obersver Design Pattern =============


class Observer{
public:
    virtual void update()=0;
};

template <typename T>

class MessageAlertObserver: public Observer{
    string user;
    T *observable;
    void sendMessage(string message){
        cout << message + user << endl;
    }
public:
    MessageAlertObserver(T *observable, string user): observable(observable),user(user){ // constructor injection
    }
    void update(){
        sendMessage("Message: Iphone is back in stock for ");
    }

};

template <typename T>

class EmailAlertObserver: public Observer{
    string user;
    T *observable;
    void sendMail(string message){
        cout << message + user << endl;
    }
public:
    EmailAlertObserver(T *observable, string user): observable(observable),user(user){ // constructor injection
    }
    void update(){
        sendMail("Email: Iphone is back in stock for ");
    }

};

class Observable{ // abstract class Observable
    public:
     virtual void notify()=0;
     virtual void addObserver(Observer *obj)=0;
     virtual void removeObserver(Observer *obj)=0;
     virtual void setStockCount(int count)=0;
     virtual int getStockCount()=0;
};

class Iphone: public Observable{
    vector<Observer*> observerList;
    int stockCount=0;//initially 0 stock count
public:
    void notify(){
        for(auto observer:observerList)
            observer->update();//respective update methods of all observers
    }
    void addObserver(Observer *obj){
        observerList.push_back(obj);
    }
    void removeObserver(Observer *obj){
        for(int i=0;i<observerList.size();i++){
            if(obj==observerList[i]){
                observerList.erase(observerList.begin()+i);
                break;
            }
        }
    }
    void setStockCount(int count){
        if(stockCount==0)
            notify();
        this->stockCount+=count;
    }
    int getStockCount(){
        return stockCount;
    }
};


int main(){
    Iphone *iphone= new Iphone();
    //make some observers for the iphone

    EmailAlertObserver<Iphone> * emailAlertObserver1 = new EmailAlertObserver<Iphone>(iphone,"Vishal");
    EmailAlertObserver<Iphone> * emailAlertObserver2 = new EmailAlertObserver<Iphone>(iphone,"Rahul");
    EmailAlertObserver<Iphone> * emailAlertObserver3 = new EmailAlertObserver<Iphone>(iphone,"Virat");
    MessageAlertObserver<Iphone> * messageAlertObserver1 = new MessageAlertObserver<Iphone>(iphone,"Jaya");
    MessageAlertObserver<Iphone> * messageAlertObserver2 = new MessageAlertObserver<Iphone>(iphone,"Tanya");
    MessageAlertObserver<Iphone> * messageAlertObserver3 = new MessageAlertObserver<Iphone>(iphone,"Sushma");

    iphone->addObserver(emailAlertObserver1);
    iphone->addObserver(emailAlertObserver2);
    iphone->addObserver(emailAlertObserver3);
    iphone->addObserver(messageAlertObserver1);
    iphone->addObserver(messageAlertObserver2);
    iphone->addObserver(messageAlertObserver3);

    iphone->setStockCount(10);

    delete iphone;
    delete emailAlertObserver1;
    delete emailAlertObserver2;
    delete emailAlertObserver3;

    delete messageAlertObserver1;
    delete messageAlertObserver2;
    delete messageAlertObserver3;
}
