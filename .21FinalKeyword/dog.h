#ifndef DOG_H
#define DOG_H

#include "animal.h"

class Dog: public Animal{
public:
    void Bark();
    
    //well we're putting here the final keyword! This means that a class that in the future might derive from Dog
    //will not be able to change the Breathe() function! So there's also no use to put the virtual keyword here
    //as this wont be able to be changed in the future
    // yet there's another way to use the final keyword, jump to cat.h
    void Breathe() override final;
};

#endif