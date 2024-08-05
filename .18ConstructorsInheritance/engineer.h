#ifndef ENGINEER_H
#define ENGINEER_H
#include "person.h"

//Engineer is doing private inheritance

class Engineer : public Person
{
    //using Person::Person; //this is inheriting the constructor, not viable, not good, can use, wont use
    friend std::ostream& operator<<(std::ostream& out , const Engineer& operand);
public:
    Engineer();
    Engineer(const std::string_view fullname, int age, const std::string_view adress, int contract_count);
    Engineer(const Engineer& source);
    ~Engineer();
    
    void build_something(){
        m_full_name = "John Snow"; // OK
        m_age = 23; // OK
    }

    int get_contract_count() const{
        return contract_count;
    }
    
private : 
    int contract_count{0};
};

#endif // ENGINEER_H