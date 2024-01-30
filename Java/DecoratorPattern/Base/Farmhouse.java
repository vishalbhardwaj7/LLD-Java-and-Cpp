package DecoratorPattern.Base;

public class Farmhouse extends BasePizza {//is-a relationship established with base class
    @Override
    public int cost (){
        return 200;
    }
}
