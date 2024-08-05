#include "person.h"
#include "engineer.h"
#include <iostream>

Engineer::Engineer(){
    std::cout << "Engineer Default Constructor Initialized" << std::endl;
}

Engineer::Engineer(const std::string_view fullname, int age, const std::string_view adress, int contract_count)
    : Person(fullname, age, adress), contract_count(contract_count)
{    
    std::cout << "Custom Constructor for Engineer..." << std::endl;
}

Engineer::Engineer(const Engineer& source)
    : Person(source), contract_count(source.contract_count)
{
    std::cout << "Copy Constructor for Engineer..." << std::endl; 
}


std::ostream& operator<<(std::ostream& out , const Engineer& operand){
     out << "Engineer [Full name : " << operand.get_full_name() <<
                    ",age : " << operand.get_age() << 
                    ",address : " << operand.get_address() <<
                    ",contract_count : " << operand.contract_count << "]";
    return out;   
}


Engineer::~Engineer()
{
}