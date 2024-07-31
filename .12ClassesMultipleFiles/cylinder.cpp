#include "cylinder.h"

//this is how you define a constructor in the cpp file
Cylinder::Cylinder(double radParam, double heightParam){
    baseRadius = radParam;
    height = heightParam;
}

//and this is how you define a method function in the cpp file
double Cylinder::Volume(){
    return pi * baseRadius * baseRadius * height;
}