#include <iostream>
#include "constants.h"
#include "cylinder.h"

int main(){
    
    Cylinder cylinder1(23,24);
    
    std::cout << "Volume of cylinder 1: " << cylinder1.Volume() << std::endl;
    
    //just like when we create a pointer for a int or a double, we can create one to a class
    
    Cylinder* cylinder2 = new Cylinder(15,24); //and just like for normal variable we can create them in the heap instead of the stack
    
    std::cout << "Volume of cylinder 2: " << cylinder2->Volume() << std::endl; //this is one way we can use the functions of a pointer class, visual studio even does it automatically but we can also do it like this
    
    std::cout << "Volume of cylinder 2: " << (*cylinder2).Volume() << std::endl; //basically dereferencing the pointer and using the function, the first one is better imo
    
    delete cylinder2; //dont forget to delete the heap memory
    
    return 0;
}