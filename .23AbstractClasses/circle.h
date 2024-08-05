#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle : public Shape
{
public:
    Circle() = default;
    Circle(double radius , std::string_view  description);
    virtual ~Circle()= default;
    
    
    double Perimeter() const override{
        return (2 * pi * radius);
    }

    double Surface() const override{
        return pi * radius* radius;
    }
    
    void StreamInsert(std::ostream& out) const override{
        out << "This is a Circle with a radius of " << radius;
    }

    
private: 
    double radius{0.0};
    
    inline static double pi{3.14159265};
};

#endif