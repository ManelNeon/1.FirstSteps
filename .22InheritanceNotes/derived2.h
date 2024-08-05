#ifndef DERIVED2_H
#define DERIVED2_H

#include "derived.h"

class Derived2: public Derived{
public:
    Derived2() = default;
    ~Derived2() override {std::cout << "Destructor for Derived2 called" << std::endl;}
    
    void Exdi() override{
        std::cout << "New Exdi" << std::endl;
    }
    
    void Lol(){
        std::cout << "Lol" << std::endl;
    }
};

#endif