#include <iostream>

const double pi{3.14159265359};


//we can put constructors that are basically things that initialize with the class, think Vector3 in Unity, if we did new Vector3, this would be 0 0 0, yet we could do Vector3(2,3,5) and put in the numbers for the positions we wanted, this is how you do it, in case we dont define any constructor in the beginning, the compiler will create an empty one automatically, this could be good as when I eventually create graphics and stuff like that, maybe the 0 value wont be good for the character so I initialize it with a 1, i dont know, just theorizing
class Cylinder{
    private:
        double baseRadius {};
        double height {};
    
    public:
        //Constructors
        Cylinder(){
            baseRadius = 2.0;
            height = 2.0;
        }
        Cylinder(double radParam, double heightParam){
            baseRadius = radParam;
            height = heightParam;
        }
    
        //Methods
        double volume(){
            return pi * baseRadius * baseRadius * height;
        }
        
        //Getters
        double GetBaseRadius(){
            return baseRadius;
        }
        
        double GetHeight(){
            return height;
        }
        
        //Setters
        void SetBaseRadius(double radParam){
            baseRadius = radParam;
        }
        
        void SetHeight(double heightParam){
            height = heightParam;
        }
};

//in this case, we're making it so that Cube() is a default constructor, be it a empty constructor, this is important because if we did not do that, we would only be able to initialize Cube() with the sideParam parameter, this might be useful in some cases, so basically doing Cube() = default, is the same as creating a empty constructor, constructors must be public to be called
class Cube{
    public:
        //Constructors
        Cube() = default;
        Cube(double sideParam){
            sideValue = sideParam;
        }
        
        double CalculateArea(){
            return sideValue * sideValue;
        }
    
    private:
        double sideValue {1.0};
};

int main(){
        
    Cylinder cylinder1;
    
    std::cout << cylinder1.volume() << std::endl;
    
    Cylinder cylinder2(2,4);
    
    std::cout << cylinder2.volume() << std::endl;
    
    return 0;
}