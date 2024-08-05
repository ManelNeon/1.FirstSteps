#include "rectangle.h"

Rectangle::Rectangle(double width , double height,std::string_view  description)
    : Shape(description), width(width), height(height)
{
}