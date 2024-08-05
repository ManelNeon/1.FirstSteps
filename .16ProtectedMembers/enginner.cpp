#include "enginner.h"

std::ostream& operator<<(std::ostream& out , const Enginner& enginner){
    out << "Person [" << enginner.first_name << " " << enginner.last_name << " " << enginner.specialty << "]";
    return out;
}

Enginner::Enginner(std::string_view firstNameParam, std::string_view secondNameParam, std::string_view gameParam){
    first_name = firstNameParam;
    last_name = secondNameParam;
    specialty = gameParam;
}
