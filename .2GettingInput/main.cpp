#include <iostream>
#include <string>

int main(){
    
    auto age = 2;
    
    std::string nickname;
    
    std::string fullname;
        
    std::cout << "Hello there, please input your full name, age and then your nickname!" << std::endl;
    
    //this code makes it so that the console can read spaces, therefore the full name requirement
    std::getline(std::cin, fullname);
    
    std::cin >> age >> nickname;
    
    std::cout << "Hello " << fullname << ", you are " << age << " years old and your nickname is " << nickname << "!" << std::endl; 
    
    /*std::cerr << "Error Message: Something is wrong" << std::endl;
    
    std::clog << "Log Message: Something happened" << std::endl;*/
    
    return 0;
}