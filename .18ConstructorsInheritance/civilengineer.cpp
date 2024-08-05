#include "person.h"
#include "engineer.h"
#include "civilengineer.h"
#include <iostream>

CivilEngineer::CivilEngineer(){
    std::cout << "Civil Engineer Default Constructor Initialized." << std::endl;
}

CivilEngineer::CivilEngineer(const std::string_view fullname, int age, const std::string_view adress, int contract_count, std::string_view m_specialty)
    : Engineer(fullname,age,adress,contract_count), m_speciality(m_specialty)
{
    std::cout << "Custom Constructor for Civil Engineer..." << std::endl;    
}

CivilEngineer::CivilEngineer(const CivilEngineer& source)
    : Engineer(source), m_speciality(source.m_speciality)
{
    std::cout << "Copy Constructor for Civil Engineer...." << std::endl;    
}

std::ostream& operator<<(std::ostream& out, const CivilEngineer& operand){
     out << "CivilEngineer [Full name : " << operand.get_full_name() <<
                    ",age : " << operand.get_age() << 
                    ",address : " << operand.get_address() <<
                    ",contract_count : " << operand.get_contract_count() <<
                    ",speciality : " << operand.m_speciality << "]";
                    		
    return out;  
}


CivilEngineer::~CivilEngineer()
{
}