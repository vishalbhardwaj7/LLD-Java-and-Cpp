package DecoratorPattern.Toppings;

import DecoratorPattern.Base.BasePizza;

public class Jalepeno extends ToppingDecorator {
    BasePizza base;//establish has-a relationship too
    public Jalepeno(BasePizza base){
        this.base=base;
    }
    public int cost(){
        return this.base.cost()+10;//add 20 rs to base cost
    }
}
