#include <iostream>
#include "shape.h"
#include "circle.h"
#include "rectangle.h"

/*
Before starting to write code, a few notes about abstract classes
if a class has at least one pure virtual function, it becomes an abstract class (the function is =0; in the end)
you cannot create objects of an abstract class, think AbstractClass a = new AbstractClass; this will give us an error
Derived classes from an abstract class must override all pure virtual functions or they will become abstract themselves
pure virtuaul functions dont have an implementation in the abstract classes, they are meant to be implemented in the children
cant call pure virtual classes on the constructor of an abstract class
the constructor of the base class is used by the deriving class to build up the base part of the object
*/

/*
Interfaces are abstract classes with only pure virtual functions and no member variables, check stream.h for more on that
*/
int main(){
    
    //Shape shape; //cant do this, shape is abstract
    
    Circle circle(24, "Big Boy");
    
    Rectangle rectangle(23, 25, "BIIIG BOY");
    
    Shape* shape = new Circle(12, "Small boy :("); //but we can do this, because we're not initializing a shape class which is abstract
    
    std::cout << circle << std::endl;
    
    std::cout << rectangle << std::endl;    
        
    return 0;
}