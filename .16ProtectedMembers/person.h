#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person
{
    friend std::ostream& operator<<(std::ostream& out, const Person& person);
public:
    Person();
    Person(std::string& first_name_param, std::string& last_name_param);
    ~Person();

//protected variables make it so that inherited classes can use these, yet in the main.cpp for example, we cannot
protected : 
    std::string first_name{"Mysterious"};
    std::string last_name{"Person"};
};


#endif // PERSON_H