#include <iostream>

const double pi{3.14159265359};
/*
//first way we made classes, also the way I know how to make them, the sizeofbigthing variable is just there to clarify myself on how the private and public variables actually work in C++
class Cylinder{
    private:
        double sizeOfBigThing {};    
    
    public:
        double volume(){
            return pi * baseRadius * baseRadius * height;
        }
        double baseRadius {};
        double height {};
};

int main(){
    
    Cylinder cylinder1;
    
    std::cout << cylinder1.volume() << std::endl;
    
    cylinder1.baseRadius = 2.4;
    cylinder1.height = 1;
    
    std::cout << cylinder1.volume() << std::endl;
    
    return 0;
}*/