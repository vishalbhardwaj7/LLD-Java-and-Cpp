#include<bits/stdc++.h>
using namespace std;

// make an abstraxct class ATM state

class ATMState{
public:

// define a default behvior for these functions 

    virtual void insertCard(ATM *atm, Card *card){
        throw "Invalid operation";
    }
    virtual void authenticatePin(ATM *atm, Card *card, int pin){
        throw "Invalid operation";
    }
    virtual void selectOperation(ATM *atm, Card *card, TransactionType *type){
        throw "Invalid operation";
    }
    virtual void checkBalance(ATM *atm, Card * card){
        throw "Invalid operation";
    }
    virtual void cashWithdrawl(ATM *atm, Card * card){
        throw "Invalid operation";
    }
    virtual void displayBalance(ATM* atm, Card *card){
        throw "Invalid operation";
    }

    virtual void returnCard(){
        throw "Invalid operation";
    }

    virtual void exit(){
        throw "Invalid operation";
    }
};

class IdleState:public ATMState{
public:

    void insertCard(ATM *atm, Card *){ /// only this functuion is possible here
        cout<<"Card is inserted" << endl;
        atm.setState(new HasCardState());
    }
};

class HasCardState: public ATMState{
public:
    HasCardState(){
        cout<< "Please insert pin"<<endl;
    }
    void authenticatePin(ATM *atm, Card *card, int pin){
        // logic to check pin
        // like fetch a pin from input and call network wiith same pin uising some algo obviously/...
        if(correctPin){
            // authenticacted
            // move to selection state
        }
        else 
        {
            // move to idle state again
            throw "incorrect pin"
        }
    } 
    void exit(){
        // move to idle state again
    }

    void returnCard(){
        //please gert your card
    }
};

class SelectionState: public ATMState{
public:
    SelectionState(){
        cout<< "Please enter your options sir/madam"<<endl;
    }


    void selectOperation(ATM *atm, Card *card, TransactionType *type){
        /// put a switch case on type of transaction and move to desired states
    }

    //exit function
    // return card
    // showOperations
};

class CashWithdrawlState:public ATMState{
public:
    void cashWithdrawl(ATM *atm, Card * card, int withdrwalAmountRequest){
        // check if the card has enough balance
        // call cashWithdrawl processor with the request and atm card 
        // just like the log processor
        CashWithdrawProcessor *withdrawProcessor =
                    new TwoThousandWithdrawProcessor(new FiveHundredWithdrawProcessor(new OneHundredWithdrawProcessor(null)));
        withdrawProcessor.processRequest(amount, atm);
        // exit
    }
};
// similary a checkBalance state
///.........


class CashWithdrawProcessor{
public:
    CashWithdrawProcessor *nextProcessor;
    CashWithdrawProcessor(CashWithdrawProcessor *processor){
        this->nextProcessor = processor;
    }

    virtual void withdraw(ATM* atm, int remAmount){ // at the run time need to decide thats why virtual
        if(!nextProcessor==NULL){
            // throw exceoptionsss or invalid balance
        }
        else
            nextProcessor.withdraw(atm, remAmount);
    }
};

class TwoThousandWithdrawProcessor: public CashWithdrawProcessor{
public:
    TwoThousandWithdrawProcessor(CashWithdrawProcessor *nextProcessor):CashWithdrawProcessor(processor){ } // set the next in runtime
    void withdraw(ATM* atm, int remAmount){ // at the run time need to decide thats why virtual
        // do some calculate to chheck the amount
        // if still amount remain then let the code continue
        // atm.dedduct(//cdvv amount)

        // else return;
        if(!nextProcessor){
            // throw exceoptionsss or invalid balance and cant process request
        }
        else
            nextProcessor->withdraw(atm, remAmount);// call other
    }
};
class FiveHundredProcessor: public CashWithdrawProcessor{
public:
    FiveHundredProcessor(CashWithdrawProcessor *nextProcessor):CashWithdrawProcessor(processor){ } // set the next in runtime
    void withdraw(ATM* atm, int remAmount){ // at the run time need to decide thats why virtual
        // do some calculate to chheck the amount
        // if still amount remain then let the code continue
        // atm.dedduct(//cdvv amount)

        // else return;
        if(!nextProcessor){
            // throw exceoptionsss or invalid balance and cant process request
        }
        else
            nextProcessor->withdraw(atm, remAmount);// call other
    }
};
class HundredProcessor: public CashWithdrawProcessor{
public:
    HundredProcessor(CashWithdrawProcessor *nextProcessor):CashWithdrawProcessor(processor){ } // set the next in runtime
    void withdraw(ATM* atm, int remAmount){ // at the run time need to decide thats why virtual
        // do some calculate to chheck the amount
        // if still amount remain then let the code continue
        // atm.dedduct(//cdvv amount)

        // else return;
        if(!nextProcessor){
            // throw exceoptionsss or invalid balance and cant process request
        }
        else
            nextProcessor->withdraw(atm, remAmount);// call other
    }
};


class USer{
    Card card;
    BankAcc acc;
};

class BankAccount{
    // balance
    // id
};

class Card{
    // pin
    // balance
};

class ATM{
    ATMState currentState;
    //
    int 2knotes;
    int 5knotes;
    int 100notes;


    //getState
    //setState
    // set balnce
    // printstatus
    // all getters and setters
};



int main(){
    // initialize 
    // set atm balance
    // create user


// flow is basically this................
    atmRoom.atm.printCurrentATMStatus();
    atmRoom.atm.getCurrentATMState().insertCard(atmRoom.atm, atmRoom.user.card);
    atmRoom.atm.getCurrentATMState().authenticatePin(atmRoom.atm, atmRoom.user.card, 112211);
    atmRoom.atm.getCurrentATMState().selectOperation(atmRoom.atm, atmRoom.user.card, TransactionType.CASH_WITHDRAWAL);
    atmRoom.atm.getCurrentATMState().cashWithdrawal(atmRoom.atm, atmRoom.user.card, 2700);
    atmRoom.atm.printCurrentATMStatus();
}