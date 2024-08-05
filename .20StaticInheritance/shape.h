#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

class Shape{
public:
    Shape();
    ~Shape();
    
    virtual void PrintCount();
    
    static int count;
};

#endif