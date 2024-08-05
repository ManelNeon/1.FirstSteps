#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include "stream.h"

class Shape: public StreamInsertable{
protected:
    Shape() = default;
    Shape(std::string_view description);
    
public:
    virtual ~Shape() = default; //if destructor isnt public wont be able to delete basePtrs
    
    //PURE VIRTUAL FUNCTIONS
    virtual double Perimeter() const = 0; 
    virtual double Surface() const = 0;
    virtual void StreamInsert(std::ostream& out) const =0;
    
private:
    std::string description;
};

#endif