#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle : public Shape{
public:
    //the override keyword is a safety check basically, it stops me from accidently changing the
    //functions name, if we take out override and write Drawh instead there would be no error
    //but with the override keyword the compiler sees that there's no function called Drawh and 
    //gives us an error, so use override keyword, important for safety
    virtual void Draw() override;
    
    //by doing this in whenever we call the circle class we can call this function and the base one
    //but in the oval class
    virtual void Draw(int a) override;
};

#endif