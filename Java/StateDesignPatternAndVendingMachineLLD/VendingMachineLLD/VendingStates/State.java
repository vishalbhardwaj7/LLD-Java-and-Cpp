package StateDesignPatternAndVendingMachineLLD.VendingMachineLLD.VendingStates;

import StateDesignPatternAndVendingMachineLLD.VendingMachineLLD.Coin;
import StateDesignPatternAndVendingMachineLLD.VendingMachineLLD.Item;
import StateDesignPatternAndVendingMachineLLD.VendingMachineLLD.VendingMachine;

import java.util.List;

public interface State {

    public void clickOnInsertCoinButton(VendingMachine machine) throws Exception;

    public void clickOnStartProductSelectionButton(VendingMachine machine) throws Exception;

    public void insertCoin(VendingMachine machine , Coin coin) throws Exception;

    public void chooseProduct(VendingMachine machine, int codeNumber) throws Exception;

    public int getChange(int returnChangeMoney) throws Exception;

    public Item dispenseProduct(VendingMachine machine, int codeNumber) throws Exception;

    public List<Coin> refundFullMoney(VendingMachine machine) throws Exception;

    public void updateInventory(VendingMachine machine, Item item, int codeNumber) throws Exception;


}
