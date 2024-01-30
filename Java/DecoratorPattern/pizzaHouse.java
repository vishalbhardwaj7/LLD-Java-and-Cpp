package DecoratorPattern;

import DecoratorPattern.Base.BasePizza;
import DecoratorPattern.Base.Margherita;
import DecoratorPattern.Toppings.ExtraCheese;
import DecoratorPattern.Toppings.Jalepeno;

public class pizzaHouse {
    public static void main(String args[]){
        //i need a margherita + Extracheese
        BasePizza pizza1 = new ExtraCheese(new Margherita());
        System.out.println(pizza1.cost());//will print 110
        //i need a margherita + jalepeno + extracheese
        BasePizza pizza2 = new Jalepeno(pizza1);
        System.out.println(pizza2.cost());
    }
}
