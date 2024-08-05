#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape{
public:
    Rectangle() = default;
    Rectangle(double width, double height, std::string_view description);
    virtual ~Rectangle() = default;
    
    
    double Perimeter() const override{
        return (2*width + 2*height);
    }
    
    double Surface() const override{
        return (width * height);
    }
    
    void StreamInsert(std::ostream& out) const override{
        out << "This is a Rectangle with a width of " << width << " and a height of " << height;
    }
    
private:
    double width{0.0};
    double height{0.0};
};

#endif