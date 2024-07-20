#include <iostream>
#include <string>

int main(){
    
    //Testing References, useful like Tom said, when making functions
    int intData = 33;
    double doubleData = 55;
    
    int& refIntData = intData;
    double&  refDoubleData = doubleData;
    
    //checking if the values are the same
    std::cout << "Int Data : " << intData << " , " << refIntData << std::endl;
    std::cout << "Double Data : " << doubleData << " , " << refDoubleData << std::endl;
    
    //by changing the reference value, we're changing the actual variable's value
    refIntData = 15;
    std::cout << "Int Data : " << intData << " , " << refIntData << std::endl;  
    
    refDoubleData = 11.22;
    std::cout << "Double Data : " << doubleData << " , " << refDoubleData << std::endl;
    
    int var1 = 25;
    const int& refvar1 = var1; // by putting const in the reference, we cannot change the value of var1 through the reference, but because var1 isnt const, we can directly change var1's value through var1 
    
    const int var2 = 25;
    const int& refvar2 = var2; // this makes it impossible to change var2's value both ways, if the reference is not const, we will not be able to assign var2 to the reference
    
    // var2 = 34; impossible chunk of code, cannot change this
    
    int var3 = 25;
    
    const int* const ptrvar3 = &var3; //by using const int* const, we're making it so that we cannot change the value in that adress in this pointer, neither can we change the adress, but because var3 isnt const we can change it directly
    
    var3 = 21; //changing it directly
    
    //*ptrvar3 = 21; cannot change the adress's value
    
    //ptrvar3 = nullptr; cannot change the adress
    
    return 0;
}