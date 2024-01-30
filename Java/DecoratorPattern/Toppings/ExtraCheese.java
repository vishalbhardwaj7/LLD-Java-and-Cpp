package DecoratorPattern.Toppings;

import DecoratorPattern.Base.BasePizza;

public class ExtraCheese extends ToppingDecorator {
    BasePizza base;
    public ExtraCheese(BasePizza base){
        this.base=base;
    }
    public int cost(){
        return this.base.cost()+10;//add 10 rs to base cost
    }
}
