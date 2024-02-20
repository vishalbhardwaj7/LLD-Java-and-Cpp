//                                              Flow chart of vending machine

//                                                        (cancel/refund)
// Idle State <-----------------------------------------------------------------------------------------------
//              (cancel/refund)                                                                              |
// Idle State <----------------------------------                                                            |
//                                              | (he can cancel)                                            | (insuff funds or again cancel button click)
//                                              |                                                            |
//           (Press Insert Cash Button)        (coins being inserted)   (select product button click)  (Product being chosen)              (It will dispense the product)
// Idle State ------------------------->       hasMoney State            -------------------------->   Selection State         --------->  Dispence Product State 
//                                                                                                                                                  |
//                                                                                                                                                  |
// Idle State <--------------------------------------------------------------------------------------------------------------------------------------


#include <bits/stdc++.h>
using namespace std;

// States of vending machine

// abstract class state

class Coin{
    int SILVER=1,NICKEL=10;/////// like this
};

class VendingState{
public:
    virtual void clickOnInsertCoinButton(VendingMachine *vendingMachine) = 0; // can be done in idle state 
    virtual void clickOnCancelButton(VendingMachine *vendingMachine) = 0; // can be implemented in selection state and hasMoney state
    virtual void clickOnProductSelectionButton(VendingMachine *vendingMachine) = 0; // can be implemented in idle state only to move to selection state
    virtual void insertCoin(VendingMachine *vendingMachine, Coin *coin) = 0; // can be implemented in hasMoney state
    virtual void choseProduct(VendingMachine *vendingMachine, int productId) = 0; // can be implemented in selection state
    virtual int getChange(int returnChangeMoney) = 0; // can be implemented in selection state 
    virtual Item* dispenseProduct(VendingMachine *vendingMachine, int codeNumber) = 0; // only in dispense state
    virtual vector<Coin*> refundFullMoney(VendingMachine *vendingMachine) = 0; // can be implemented in selectionState if the money does not matches the required amount
    virtual void updateInventory(VendingMachine* vendingMachine, Item *item, int codeNumber) = 0;//can only be done in idle state
};

class IdleState: public VendingState{
public:
    IdleState(){
        cout << "Machine is now in Idle State" << endl;
    }
    IdleState(VendingMachine *vendingMachine){ // parametertized consturct
        cout << "Machine is now in Idle State" << endl;
        machine.setCoinList(empty);
    }
    void clickOnInsertCoinButton(VendingMachine *vendingMachine){
        vendingMachine->setState(new HasMoneyState());
        
    } 
    void clickOnCancelButton(VendingMachine *vendingMachine){
        throw "Not possible to perform this operation in current state";
    }
    void clickOnProductSelectionButton(VendingMachine *vendingMachine){
        throw "Not possible to perform this operation in current state";
    } 
    void insertCoin(VendingMachine *vendingMachine, Coin *coin){
        throw "Not possible to perform this operation in current state";
    }
    void choseProduct(VendingMachine *vendingMachine, int productId){
        throw "Not possible to perform this operation in current state";
    }
    int getChange(int returnChangeMoney){
        throw "Not possible to perform this operation in current state";
    }
    Item* dispenseProduct(VendingMachine *vendingMachine, int codeNumber){
        throw "Not possible to perform this operation in current state";
    }
    vector<Coin*> refundFullMoney(VendingMachine *vendingMachine){
        throw "Not possible to perform this operation in current state";
    }
    void updateInventory(VendingMachine* vendingMachine, Item *item, int codeNumber){
        vendingMachine.getInventory().addItem(item.codeNumber); // this can be done only here
    }

};
class HasMoneyState: public VendingState{
public:
    HasMoneyState(){
        cout<< "Product is now in HasMoney state" << endl;
    }
    void clickOnInsertCoinButton(VendingMachine *vendingMachine){
        return ;// not do anything best...
    } 
    void clickOnCancelButton(VendingMachine *vendingMachine){
        // call refundMoney and go to back
        // set state to idle
    }
    void clickOnProductSelectionButton(VendingMachine *vendingMachine){
        machine.setState(new SelectionState());
    } 
    void insertCoin(VendingMachine *vendingMachine, Coin *coin){
        // insert coins in vending machine object by calling the function
    }
    void choseProduct(VendingMachine *vendingMachine, int productId){
        throw "Not possible to perform this operation in current state";
    }
    int getChange(int returnChangeMoney){
        throw "Not possible to perform this operation in current state";
    }
    Item* dispenseProduct(VendingMachine *vendingMachine, int codeNumber){
        throw "Not possible to perform this operation in current state";
    }
    vector<Coin*> refundFullMoney(VendingMachine *vendingMachine){
        // refund full money by emptiend the coin list and return coin lisgt to user 
        // put to idle state also
    }
    void updateInventory(VendingMachine* vendingMachine, Item *item, int codeNumber){
        // throw exception here tooo
    }

};
class SelectionState: public VendingState{
public:
    void clickOnInsertCoinButton(VendingMachine *vendingMachine){
        throw "Not possible to perform this operation in current state";
    } 
    void clickOnCancelButton(VendingMachine *vendingMachine){
        // call refund money and p
    }
    void clickOnProductSelectionButton(VendingMachine *vendingMachine){
        // return
    } 
    void insertCoin(VendingMachine *vendingMachine, Coin *coin){
        // throw errror
    }
    void choseProduct(VendingMachine *vendingMachine, int productId){
        // chose product of machine and also check if coin total < = inverntort item price
        // call getChanfgee 
        // put it in dispense state
        vendingMachine->swetState(new DispenseState(machine, codeNumber));
    }
    int getChange(int returnChangeMoney){
        // implement
    }
    Item* dispenseProduct(VendingMachine *vendingMachine, int codeNumber){
        // throw error
    }
    vector<Coin*> refundFullMoney(VendingMachine *vendingMachine){
        // same logic to refund
        // put to idel state also
    }
    void updateInventory(VendingMachine* vendingMachine, Item *item, int codeNumber){
        // cant do
    }

};


class DispenseState: public VendingState{
public:
    DispenseState(VendingMachine *vendingMachine, int codeNumber){
        // get inverntory and call update invernotry pmethod of that nventory
        // also set the state to idle now//\\\
        // write dispense logic if u want to
    }
    // throw error on all others
    void clickOnInsertCoinButton(VendingMachine *vendingMachine){

    } 
    void clickOnCancelButton(VendingMachine *vendingMachine){

    }
    void clickOnProductSelectionButton(VendingMachine *vendingMachine){

    } 
    void insertCoin(VendingMachine *vendingMachine, Coin *coin){

    }
    void choseProduct(VendingMachine *vendingMachine, int productId){

    }
    int getChange(int returnChangeMoney){

    }
    Item* dispenseProduct(VendingMachine *vendingMachine, int codeNumber){

    }
    vector<Coin*> refundFullMoney(VendingMachine *vendingMachine){

    }
    void updateInventory(VendingMachine* vendingMachine, Item *item, int codeNumber){

    }

};

class Item{
public:// to avoid getter and setter i have made them public but not a good approach
    int itemNo;
    int price;
};

class ItemShelf{
public:
    Item * item;
    bool isSold;
    int id;
};

class Inventory{
public:
    vector<ItemShelf> *stacks;// whatever we can name it
// getters and setters

    void addItem(Item *item){
        //logic we can give to add in array
    }
    void removeItem(Item *item){

    }
    Item* getItem(int codeNumber){

    }
    void updateSoldItem(int codeNumber){
        // update sold by boolean of the item
    }

};

class VendingMachine{
    VendingState *vendingState;
    Inventory *inventory;
    vector<Coin*> coinList;// all the coins in the vending machine

    // getters and setters
    VendingMachine(){
        vendingState = new IdleState();
        // set inverntory;
        // empty coin list or just add some coins
    }
};

void fillUpInveryory(Invetneroty){
    //............
}

int main(){
    // main flow
    // make a new machine
    VendingMachine *machine = new VendingMachine();
    // fill a constant inventory //
    // can write a sepearted function for this

    // display invenyry


    //1. user click on insert button
    // internally automatically it goes to hasmoney

    // 2. insert coint
    // 4. insrr more coin

    // // click on prodcut selection buttton

    // state internally changes

    // display inverntroy


    // now click on chose product with id

    //every thing happens inrernallt 
}