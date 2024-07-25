#include <iostream>
#include "compare.h"
#include "operations.h"

//I already have a pretty big confidence in using functions, so instead of following the tutorial I'm gonna test the header file a bit

void StartingHeaderUse(){
    
    int maxNumber = max(24,21);
    
    std::cout << maxNumber << std::endl;
    
    int minNumber = min(21,12);
    
    std::cout << minNumber << std::endl;
    
    std::cout << MultiplyNumbers(24, 2) << std::endl;
    
    std::cout << DivideNumbers(13,0) << std::endl;
}

void SayAge(int age){
    ++age;
    std::cout << "You are now" << age << std::endl;
}

void FunctionByValue(){
    //so with this I discovered that if I pass on a variable, it is not like C# where i changes that variables value, but instead only the one existing inside the function
    
    int age = 23;
    
    //age is 23
    std::cout << age << std::endl;
    
    //in this function we add 1 to age
    SayAge(age);
    
    //yet because that instance of the variable dies inside the function, in here age will still be 23
    std::cout << age << std::endl;
}

void AddAge(int* age){
    ++(*age);
    std::cout << "You are now" << *age << std::endl;
}

void FunctionByPointer(){
    //so just like Tom said, you can have a pointer as a parameter instead of a copy, this is better in C++ as this actually changes that variables value, as we're sending in the adress instead of the value
    
    int age = 23;
    
    //age is 23
    std::cout << age << std::endl;
    
    //in this function we add 1 to age
    AddAge(&age);
    
    //because we're changing the adress, in here age will be 24 now!
    std::cout << age << std::endl;
}

void ModifyAge(int& age){
    ++(age);
    std::cout << "You are now " << age << std::endl;
}

void FunctionByReference(){
    //We can also have a reference, that does the same as a pointer, changing its value directly, the problem with this is, we cannot send in a null reference, for example in a code where i'd like for that to happen i'd prefer a pointer, and i'd send in a nullptr, but in a reference I cannot do that
    
    int age = 23;
    
    //age is 23
    std::cout << age << std::endl;
    
    //in this function we add 1 to age
    ModifyAge(age);
    
    //because we're accessing the reference, in here age will be 24 now!
    std::cout << age << std::endl;
}

//we can overload the function by changing its parameters, I knew this was possible but still had my doubts of how actually to do that
int maximum(int a, int b){
    return a + b;
}

int maximum(double a, double b){
    return a + b;
}

//Because this has the same parameters as the maximum above, changing the return type wont make it sufficient for an overload
/*double maximum(double a, double b){
    return a + b;
}*/

//various different ways to overload a function with pointers/references
int maximum (int* a, int* b){
    return (*a + *b);
}

int maximum(int* a, int b){
    return (*a + b);
}

int maximum(int& a, int* b){
    return (a + *b);
}

//in conclusion, pointers and references count as different parameters to just int

int main(){
    
    //FunctionByReference();
    
    resina();
    
    
    return 0;
}