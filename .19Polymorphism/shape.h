#ifndef SHAPE_H
#define SHAPE_H

class Shape{
public:
    virtual void Draw();
    
    //so in case we have an overload for a function like this, whenever we override, we are basically
    //removing this function from existence in the f.e the circle class, so in order for it to also exist
    //we're forced to also override this case
    virtual void Draw(int a);
};

#endif