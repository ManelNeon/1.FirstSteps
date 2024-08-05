#include "nurse.h"

std::ostream& operator<<(std::ostream& out , const Nurse& enginner){
    out << "Person [" << enginner.first_name << " " << enginner.last_name << " " << enginner.specialty << "]";
    return out;
}

Nurse::Nurse(std::string_view firstNameParam, std::string_view secondNameParam, std::string_view gameParam){
    first_name = firstNameParam;
    last_name = secondNameParam;
    specialty = gameParam;
}
