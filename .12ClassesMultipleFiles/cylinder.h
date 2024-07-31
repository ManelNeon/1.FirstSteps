#ifndef CYLINDER_H
#define CYLINDER_H

#include "constants.h"

//like Tom said, we can include the whole class in the Header file, or we can go to the cylinder.cpp and define the functions there, we can also define the constructors
class Cylinder{
    public:
        Cylinder() = default;
        Cylinder(double radParam, double heightParam);
        
        //check cylinder.cpp to see how to do it
        double Volume();
        
        double GetBaseRadius(){
            return baseRadius;
        }
        
        double GetHeight(){
            return height;
        }
        
        void SetBaseRadius(double radParam){
            baseRadius = radParam;
        }
        
        void SetHeight(double heightParam){
            height = heightParam;
        }
        
    private:
        double baseRadius {1};
        double height {1};
};

#endif