#include <iostream>
#include "civilengineer.h"

int main(){
    
    CivilEngineer civ1;
    
    /*
    Result:
    Person default Constructor initialized.
    Engineer Default Constructor Initialized
    Civil Engineer Default Constructor Initialized.
    
    basically when we create a CivilEngineer class, because its a son of the engineer that is a son of the person
    this will make it so that all previous default Constructors will play out, simple as that
    */
    
    Person p1("Jose Castelo Branco", 65, "Prisao");
    
    std::cout << p1 << std::endl;
    
    Engineer e1("Zezito", 35, "Casa Do Benfica", 3);
    
    std::cout << e1 << std::endl;
    
    CivilEngineer c1("Toze", 25, "Casa do PROTO", 5, "Trolhices");
    
    std::cout << c1 << std::endl;
    
    //one way to copy data from one to another, but I did it with pointers and in the heap just cus, this was before making any copy constructor, letting the compiler do it alone
    //we can do it like this normally no problem, yet if inside the class we do any memory allocation, this is bad, because we might have two classes with the same adress on a pointer, no good, no no good
    CivilEngineer* c2 = new CivilEngineer(c1);
    
    std::cout << *c2 << std::endl;
    
    e1.Person::get_full_name(); // a way to access parent functions, this is cool in case we override some function
    
    delete c2;
    
    return 0;
    
    
}