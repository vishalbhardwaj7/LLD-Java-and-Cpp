#include<bits/stdc++.h>
using namespace std;

class Expense{ // dumb object
    User paidBy;
    double totalAmount;
    vector<Split*> splits;
    string id;
    SplitType splitType;
    // contructor to make and return the dumb object
    Expense(){ // take all params and assign and return 

    }
};

class ExpenseController{
    // has an create expense api
    // it also has
    BalanceSheetController * balanceSheetController; // 
public:
    Expense * createExpense(){ // get splits , user paid by, total amount, and generate an uuid
        // take all info and return a expense 
        // on bais of split type passed get a required ExpenseSplit object;
        ExpenseSplit * expenseSplit = (new ExpenseSplitFactory())->getExpenseSplitObject(splitType);
        // call validate request of that split type
        // call
        bool isValid = expenseSplit->validateRequest();//pass splits here to see the user is demanding the right splits with his/her total amount and distribution
        // now finally check
        if(isValid){
            //create an epxense
            // also call 
            balanceSheetController->updateUserExpenseBalanceSheet(paidByYser,splitDetial,expenseAmount);// its like notifying this object after successs expense creation to update all users' balance sheets
        }
        else{
            // dont creat ean epxense
        }
    }
};

class ExpenseSplitFactory{
public:
    ExpenseSplit* getExpenseSplitObject(SplitType splitType){
        // switch case on splitTypew to get the required expense split object
        // also in case of an unoknown split type we can throw an exception or to avoid null object exception
        // we can possibly try to define a null object splittype where it will use null object design pattern
    }
};

class ExpenseSplit{ // interface or abstract class
public:
    virtual bool validateRequest()=0;
};

class EqualExpenseSplit:public ExpenseSplit{
public:
    bool validateRequest(){ // take all the splits and total money and perform logic to validat eth erequest

    }
};
class UnEqualExpenseSplit: public ExpenseSplit{
public:
    bool validateRequest(){ // take all the splits and total money and perform logic to validat eth erequest

    }
};
class PercentageExpenseSplit:  public ExpenseSplit{
public:
    bool validateRequest(){ // take all the splits and total money and perform logic to validat eth erequest

    }
};

class ExpenseSplitFactory{

};

enum SplitType{
    EQUAL,UNEQUAL,PERCENTAGE
};

class Split{
    User user;
    double amountOwe;
    int percentage;// will explicitly tell how much percentage is this split, group controller can give this logic or lets see
};
 
class User{
    string name;
    int id;
    UserVsFriendsBalanceSheet balanceSheet;
};

class UserController{ // this if for creating direct splits without groups....... or even within a group there is a user controlller
    vector< User*> users;
    // crud operations 
    // add
    // remove
    // getUser on base of name 
};

enum AmountType{
    OWE, GET
};

class Balance{
    int amount;
    AmountType amountType;
};

class UserVsFriendsBalanceSheet{
    unordered_map < User*, Balance> mp;
    double totalExpenses;
    double totalPaid;
    double totalOwed;
    double totalGetBack;
};

class BalanceSheetController{ // observer
    // 
public:
    void updateUserExpenseBalanceSheet(){// takes paidBy, vector<Split> splits, expense
        // write logic here to update the balance sheet of all users
        // basically get user and balance sheet of each user from vector of split and do plus minus for each person with that person
    }
};

class Group{
    vector<User*> users;
    vector<Expense*> expenses;
    string id;
    string name;
    string desc;
    ExpenseController expenseController;
    // has an expense controller
    // createEXpense(){
        //call api and also put the expense in list of expenses
    //}
};

class GroupController{
    //crud operation on groups
    // has a list of groups
    vector<Group*> groups;
    // addGroup
    // get group
};


class SplitWise{
    UserController *userController;
    GroupController *groupController;
    // demo
public:
    void  demo(){
        // make some users
        // add them to group
        // add them to group controlller
        // now 
        // make 3 4 split objects
        
        // vector<Split> splits;
        // Split split1 = new Split(userController.getUser("U1001"), 300);
        // Split split2 = new Split(userController.getUser("U2001"), 300);
        // Split split3 = new Split(userController.getUser("U3001"), 300);
        // splits.push_back(split1);
        // splits.push_back(split2);
        // splits.push_back(split3);

        // now try to call group.createExpenseAPI
        // group.createExpense("Exp1001", "Breakfast", 900, splits, ExpenseSplitType.EQUAL, userController.getUser("U1001"));
        // now a expense is created
        // now try to print balance sheets of all users 
    }
};


int main(){
    SplitWise app;
    app.demo();
}