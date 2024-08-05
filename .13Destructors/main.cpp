#include <iostream>
#include <string_view>

//so destructors are what is called whenever a class object is about to die, this happens in various cases, they could happen when a program is about to end(this example), whenever we delete the class object, a destructor is also called in case the object lives in the stack and it's range is over (range over = the end of the {})

//apparently destructors are also called whenever an object is passed by value to a function and in some compilers when a local object is returned from a function

class Dog{
    public:
        Dog() = default;
        Dog(std::string_view nameParam, std::string_view breedParam, int ageParam);
        ~Dog(); //syntax to declare a destructor
        
    private:
        std::string name = "None";
        std::string breed = "None";
        int* pAge {nullptr};
};

Dog::Dog(std::string_view nameParam, std::string_view breedParam, int ageParam){
    name = nameParam;
    breed = breedParam;
    pAge = new int{ageParam};
    std::cout << "Created memory for the age in the heap" << std::endl;
}

Dog::~Dog(){
    delete pAge;
    std::cout << "Deleted age memory in the heap " << name <<std::endl;
}

//this is bad in this program, why? I'll explain, there's a thing called copy constructor (or something like that) and because we dont have any, the compiler will see this and copy the name, the breed and then THE ADRESS, because we have a pointer, and not copy the value of the adress, so when SomeFunc ends, and dogParam is destroyed, calling the destructor, we will delete the adress on page that is the same adress of the dog we sent in here, making it so that when we call the age of the firstdog, there will no longer be a 2, and when the first dog is deleted, then we will have a crash or an error because we're deleting a pointer twice basically
void SomeFunc(Dog dogParam){
    
}

int main(){
    Dog dog("Jose", "Cavalo", 2);
    
    Dog dog2("Jose 2" , "Cavalo" , 4);
    
    Dog dog3("Jose 3", "Cavalo", 5);
    
    std::cout << "Done!" << std::endl;
    
    //just a fact, whem we create the dog variables they are created in order, as expected, but when the {} end, they will be deleted in the reverse, think of it like, okey you put a bunch of books in top of each other, and the first book you put on the stack will be the last
    
    //build to see
    
    return 0;
}