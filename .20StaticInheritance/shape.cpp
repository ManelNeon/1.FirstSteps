#include <iostream>
#include "shape.h"

int Shape::count = 0;

Shape::~Shape(){
    --count;
}

Shape::Shape(){
    ++count;   
}

void Shape::PrintCount(){
    std::cout << "There is now: " << count << " instances of Shape." << std::endl;
}