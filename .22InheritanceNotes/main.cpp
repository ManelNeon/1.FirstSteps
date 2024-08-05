#include <iostream>
#include "derived2.h"

void FunctionParameters(){
    Base base1;
    
    auto result = base1.Add(); //calling the base::add, and the result is 11
    
    std::cout << result << std::endl;
    
    Derived derived1; //calling the derived::add, and the result is 22
    
    result = derived1.Add();
    
    std::cout << result << std::endl;
    
    //but here although we're calling the derived::add, because we're using a base*, we're gonna use
    //the base parameters, which are 5 + 5, but we'll use the derived::add function override, so
    //the result is 5 + 5 + 2, so 12
    Base* basePtr = &derived1; 
    
    result = basePtr->Add();
    
    std::cout << result << std::endl;
    
    //so try not to use default arguments with virtual functions, can give a big headache
}

void DestructorInheritence(){
    Base* basePtr2 = new Derived2;
    
    delete basePtr2; //when we do this, the destructor will only destroy the base part and not the derived part so --> memory leak
    //this can be solved by marking our destructors as virtual
    
    //now that we made our destructors virtual, and the last one an override because theres no need to virtual signal it, the
    //delete baseptr2 will now completely delete the memory    
    std::cout << "------------------" << std::endl;
}

void DynamicCasting(){
    //so Dynamic_cast are cool, really cool
    
    Base* baseptr = new Derived;
    
    //this is super cool, so dynamic cast basically sees if there is a Derived Class in that adress, and then stores it in the new
    //adress, but if there isnt none, it will store a nullptr, in case we do this with a reference, there's no way to actually check
    //if there was no valid Derived Class inside that Base pointer
    //its a cool thing YET, we shouldnt overuse it, overusing the dynamic casting could be a sign of bad design
    Derived* derivedPtr = dynamic_cast<Derived*>(baseptr);
    
    if (derivedPtr){
        derivedPtr->Exdi();
    }else{
        std::cout << "DerivedPtr is null" << std::endl;
    }
}

//Dont call virtual functions on construccotrs or destructors, is gonna end bad

int main(){
    
    
    
    return 0;
}