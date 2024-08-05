#ifndef ENGINNER_H
#define ENGINNER_H

#include "person.h"

class Enginner : protected Person{
    friend std::ostream& operator << (std::ostream& out, const Enginner& enginner);
    
public:
    Enginner() = default;
    Enginner(std::string_view firstNameParam, std::string_view secondNameParam, std::string_view gameParam);
    
private:
    std::string specialty {"None"};
};

#endif