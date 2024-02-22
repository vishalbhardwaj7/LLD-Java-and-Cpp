#include <bits/stdc++.h>
using namespace std;

// it is just a layer to convert an adaptee response into a client specific response

class WeightMachine{
public:
    virtual int getWeightInKgs(){}
};

class WeightMachineForBabies: public WeightMachine{
public:
    WeightMachineForBabies(){}
    int getWeightInKgs(){
        return 45;
    }
};

class WeightMachineAdapter{
public:
    virtual int getWeightInPounds(){}
};


class WeightMachineAdapterPounds: public WeightMachineAdapter{
    WeightMachine *weightMachine;
public:
    WeightMachineAdapterPounds(WeightMachine *weightMachine):weightMachine(weightMachine){}
    int getWeightInPounds(){
        return 0.45*weightMachine->getWeightInKgs();
    }
};


int main(){
    // client needs weight in pounds
    WeightMachineAdapterPounds *adapter = new WeightMachineAdapterPounds(new WeightMachineForBabies());
    cout<<adapter->getWeightInPounds();
}




// class WeightMachine {
// public:
//     virtual int getWeightInKgs() { }
// };

// class WeightMachineForBabies : public WeightMachine {
// public:
//     WeightMachineForBabies() {}
//     int getWeightInKgs() {
//         return 45;
//     }
// };

// class WeightMachineAdapter {
// public:
//     virtual int getWeightInPounds() { }
// };

// class WeightMachineAdapterPounds : public WeightMachineAdapter {
//     WeightMachine *weightMachine;

// public:
//     WeightMachineAdapterPounds(WeightMachine *weightMachine) : weightMachine(weightMachine) {}
//     int getWeightInPounds() {
//         return 0.45 * weightMachine->getWeightInKgs();
//     }
// };

// int main() {
//     // client needs weight in pounds
//     WeightMachineAdapterPounds *adapter = new WeightMachineAdapterPounds(new WeightMachineForBabies());
//     cout << adapter->getWeightInPounds() << endl;

// }
