#ifndef BASE_H
#define BASE_H

#include <iostream>

class Base{
public:
    Base() = default;
    virtual ~Base(){ std::cout << "Base Destructor Called" << std::endl;}
    
    virtual double Add(double a = 5, double b = 5) const{
        std::cout << "Base::Add called" << std::endl;
        return a + b + 1;
    }
};

#endif