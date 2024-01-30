package DecoratorPattern.Base;

public class Margherita extends BasePizza{//is-a relationship established with base class

    @Override
    public int cost() {
        return 100;
    }
    
}
