#include <iostream>
#include "circle.h"
#include "oval.h"


int main(){
    
    Shape shape1;
    
    shape1.Draw();
        
    Circle circle1;
    
    circle1.Draw();
    
    Oval oval1;
    
    oval1.Draw();
    
    //doing it like this
    Shape* shape2 = &oval1;
    
    //and then this, the Draw function wont recognize it's a oval, and will draw a Shape instead, but if we //this is static Binding!!
    //put virtual theeeen it starts working! //this is dynamic Binding!!
    //Dynamic Binding has a bigger sized :(
    shape2->Draw();
    
    //this is called slicing, it slices what it doenst know or need and keeps only what it needs, circle is child of shape so it only keeps what shape initially had
    Shape shape3 = circle1;
    
    return 0;
}