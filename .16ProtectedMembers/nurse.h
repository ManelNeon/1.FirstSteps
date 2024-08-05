#ifndef NURSE_H
#define NURSE_H

#include "person.h"

class Nurse : private Person{
    friend std::ostream& operator << (std::ostream& out, const Nurse& enginner);
    
public:
    Nurse() = default;
    Nurse(std::string_view firstNameParam, std::string_view secondNameParam, std::string_view gameParam);
    
private:
    std::string specialty {"None"};
};

#endif