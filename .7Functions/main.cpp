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

void SayAge(int age){
    ++age;
    std::cout << "You are now" << age << std::endl;
}

int main(){
    
    return 0;
}