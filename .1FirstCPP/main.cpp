#include <iostream>

//function that adds numbers
int add_numbers(int numberOne, int numberTwo){
    return numberOne + numberTwo;
}

int main(){
    
    //testing the two ways you can give variables data
    int firstNumber {3};
    
    int secondNumber {5};
    
    int thirdNumber = 15;
    
    int fourthNumber = 25;
    
    std::cout << add_numbers(firstNumber, secondNumber) << std::endl;
    
    std::cout << add_numbers(thirdNumber, fourthNumber) << std::endl;
    
    std::cout << add_numbers(5, 15) << std::endl;
    
    std::cout << add_numbers(1515, 120958215) << std::endl;
    
    //testing the limit in intengers
    std::cout << add_numbers(999999999, 999999999);
    
    return 0;
}