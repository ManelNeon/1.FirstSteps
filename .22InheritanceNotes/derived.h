#ifndef DERIVED_H
#define DERIVED_H

#include "base.h"

class Derived : public Base{
public:
    Derived() = default;
    virtual ~Derived(){std::cout << "Derived Destructor Called" << std::endl;}
    
    double Add(double a = 10, double b = 10) const override{
        std::cout << "Derived::Add called" << std::endl;
        return a + b + 2;
    }
    
    virtual void Exdi(){
        std::cout << "Exdi" << std::endl;
    }
};

#endif