package FactoryPattern;

public class MainClass {
    public static void main (String args[]){
        ShapeFactory shapeFactory = new ShapeFactory();
        Shape shapeObj=shapeFactory.getShape("CIRCLE");//if we want to create object and we have a big repo so factory gives us a way to remove duplicacy
        shapeObj.draw();//prints this is circle
    }
}
