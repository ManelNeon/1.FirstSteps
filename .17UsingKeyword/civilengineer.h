#ifndef CIVIL_ENGINEER_H
#define CIVIL_ENGINEER_H

#include "engineer.h"
class CivilEngineer : public Engineer
{
    friend std::ostream& operator<<(std::ostream&, const CivilEngineer& operand);
public:
    CivilEngineer();
    ~CivilEngineer() ;
    
    void build_road(){
        get_full_name(); // accessible because the "using" keyword is set in the enginner class, even though its private inheritance
        //m_full_name = "Daniel Gray"; //Compiler error, we're only turning the getters into accessible, not the variables
        //m_age = 45; // Compiler error, not accessible

        add(10,2);
        add(10,2,4);
    }

    public : 
        //using Person::do_something; // Compiler error, not acessible
	
private : 
    std::string m_speciality{"None"};

};

#endif // CIVIL_ENGINEER_H