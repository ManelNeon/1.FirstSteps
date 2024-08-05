#ifndef CIVIL_ENGINEER_H
#define CIVIL_ENGINEER_H

#include "engineer.h"
class CivilEngineer : public Engineer
{
    friend std::ostream& operator<<(std::ostream&, const CivilEngineer& operand);
public:
    CivilEngineer();
    CivilEngineer(const std::string_view fullname, int age, const std::string_view adress, int contract_count, std::string_view m_specialty);
    CivilEngineer(const CivilEngineer& source);
    ~CivilEngineer();
    
    void build_road(){
        get_full_name(); 

        add(10,2);
        add(10,2,4);
    }
	
private : 
    std::string m_speciality{"None"};

};

#endif // CIVIL_ENGINEER_H