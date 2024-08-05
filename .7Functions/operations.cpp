#include <iostream>
#include "compare.h"

int DivideNumbers(int a, int b){
    if (b == 0){
        std::cout << "Can't Divide by 0" << std::endl;
        return 0;
    }
    
    return a / b;
}

int MultiplyNumbers(int a, int b){
    return a * b;
}