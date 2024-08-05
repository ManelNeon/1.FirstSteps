#include <iostream>
#include "shape.h"
#include "elipse.h"

int main(){
    
    Shape shape1;
    
    shape1.PrintCount(); //one count
    
    Shape shape2;
    
    shape2.PrintCount(); // two count
    
    Elipse elipse1;
    
    //and unless we create a static variable of its own for elipse, this will print out that it has three
    //instances, so now we'll create a static variable of it's own
    elipse1.PrintCount();
    //after we created his own static variable, there is now only 1 instance of the elipse
    
    //but if we print out the shape there are now three instnaces of shape because elipse is also a shape, very gucci
    shape2.PrintCount();
    
    return 0;
}