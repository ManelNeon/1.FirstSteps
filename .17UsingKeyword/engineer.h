#ifndef ENGINEER_H
#define ENGINEER_H
#include "person.h"

//Engineer is doing private inheritance

class Engineer : private Person
{
friend std::ostream& operator<<(std::ostream& out , const Engineer& operand);
public:
    Engineer();
    ~Engineer();
    
    void build_something(){
        m_full_name = "John Snow"; // OK
        m_age = 23; // OK
        //m_address = "897-78-723"; //Compiler error, because m_adress is a private member variable of Person
    }

    //so basically what the using keyword does is this: when we do private Person, it turns things that were protected or public in the Person class into private. Due to us using private inheritance they would normally be private for someone inheriting the Engineer class, yet the "using" keyword can turn those private members into public/protected ones
    public : 
        using Person::add;

    protected : 
        using Person::get_full_name;
        using Person::get_age;
        using Person::get_address;
        //using Person::m_address; // Compiler error, m_adress was never accessible by Enginner, so we cannot just turn it into a protected variable

    int get_contract_count() const{
        return contract_count;
    }
    
private : 
    int contract_count{0};
};

#endif // ENGINEER_H