#include<bits/stdc++.h>
using namespace std;


//Bases
class BasePizza{
public:
    virtual int cost()=0;
};
class FarmHouseBasePizza: public BasePizza{
public:
    int cost(){
        return 10;
    }
};
class MargheritaBasePizza: public BasePizza{
public:
    int cost(){
        return 12;
    }
};

//Toppings
class ToppingDecorator: public BasePizza{ // is- a Base Pizza and also an abstract class

};

// template <typename T>
class Jalepino: public ToppingDecorator{
    BasePizza *basePizza; // base pizza has-a
public:
    Jalepino(BasePizza *basePizza):basePizza(basePizza){}// constructor injection
    int cost(){
        return this->basePizza->cost()+20;
    }
};
class ExtraCheese: public ToppingDecorator{
    BasePizza *basePizza; // base pizza has-a
public:
    ExtraCheese(BasePizza *basePizza):basePizza(basePizza){}// constructor injection
    int cost(){
        return this->basePizza->cost()+30;
    }
};

int main(){
    FarmHouseBasePizza *farmHouseBasePizza = new FarmHouseBasePizza();
    cout<< farmHouseBasePizza->cost()<<endl;// should be 10

    ExtraCheese *extraCheese = new ExtraCheese(farmHouseBasePizza);

    cout<< extraCheese->cost()<<endl;//should be 40

    Jalepino *jalepino = new Jalepino(extraCheese);

    cout<< jalepino->cost()<<endl;//should be 60
}