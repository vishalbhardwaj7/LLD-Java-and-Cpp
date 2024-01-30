package ATMMachineLLD.AmountWithdrawl;

import ATMMachineLLD.ATM;
public class TwoThousandWithdrawProcessor extends CashWithdrawProcessor {

    public TwoThousandWithdrawProcessor(CashWithdrawProcessor nextCashWithdrawProcessor) {
        super(nextCashWithdrawProcessor);
    }

    public void withdraw(ATM atm, int remainingAmount) {

       int required =  remainingAmount/2000; //1
       int balance = remainingAmount%2000; // 700

       if(required <= atm.getNoOfTwoThousandNotes()) {
           atm.deductTwoThousandNotes(required);
       }
       else if(required > atm.getNoOfTwoThousandNotes()) {
           atm.deductTwoThousandNotes(atm.getNoOfTwoThousandNotes());//all notes deduct
           balance = balance + (required-atm.getNoOfTwoThousandNotes()) * 2000;
        }

       if(balance != 0){
           super.withdraw(atm, balance);
       }
    }
}

