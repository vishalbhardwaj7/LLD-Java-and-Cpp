#include<bits/stdc++.h>
using namespace std;

// -------------   Factory Design Pattern -------------

class Shape{ // abstract class shape
public:
    virtual void print()=0;
    virtual void hello()=0;
};

class Rectangle: public Shape{
public:
    void print(){
        cout<<"This is a rectangle" <<endl;
    }
    void hello(){
        cout<< "hello" << endl;
    }
};
class Square: public Shape{
public:
    void print(){
        cout<<"This is a Square" <<endl;
    }
    void hello(){
        cout<< "hello" << endl;
    }
};
class Triangle: public Shape{
public:
    void print(){
        cout<<"This is a Triangle" <<endl;
    }
    void hello(){
        cout<< "hello" << endl;
    }
};

// -- Make a factory
class ShapeFactory{ // returns a shape
public: 
    Shape* getShape(string shape){
        if(shape=="SQUARE")
            return new Square();
        if(shape=="TRIANGLE")
            return new Triangle();
        if(shape=="RECTANGLE")
            return new Rectangle();

        throw; // exception to be handled
    }
};
int main(){
    // make a new factory
    ShapeFactory *factory= new ShapeFactory();
    Shape *triangle= factory->getShape("TRIANGLE");
    triangle->hello();
    Shape *shape2= factory->getShape("SQUARE");
    // cout << type_info
    shape2->print();
}