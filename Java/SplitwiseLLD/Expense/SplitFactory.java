package SplitwiseLLD.Expense;
import SplitwiseLLD.Expense.Split.ExpenseSplit;
import SplitwiseLLD.Expense.Split.EqualExpenseSplit;
import SplitwiseLLD.Expense.Split.UnequalExpenseSplit;
import SplitwiseLLD.Expense.Split.PercentageExpenseSplit;

public class SplitFactory {

    public static ExpenseSplit getSplitObject(ExpenseSplitType splitType) {

        switch (splitType) {
            case EQUAL:
                return new EqualExpenseSplit();
            case UNEQUAL:
                return new UnequalExpenseSplit();
            case PERCENTAGE:
                return new PercentageExpenseSplit();
            default:
                return null;
        }
    }
}
