#include <iostream>
#include "dog.h"
#include "cat.h"

//so what does the final keyword actually do? well that's simple, jump over to animal.h

int main(){
    
    Dog dog1;
    
    dog1.Breathe(); // a dog breathed
    
    dog1.Bark(); // barked
    
    Cat cat1;
    
    cat1.Breathe(); // breathing
    
    cat1.Meow(); // meowed
    
    Animal* animalPointer = &dog1;
    
    animalPointer->Breathe(); // a dog barked, the function was overriden still, but it cant be changed in the future
    
    Animal animal1;
    
    animal1.Breathe(); // breating
    
    return 0;
}