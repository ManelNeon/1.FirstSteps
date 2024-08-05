#ifndef OVAL_H
#define OVAL_H

#include "shape.h"

class Oval : public Shape{
public:
    //because we dont have the Draw(int a) override we cannot call that version, and we 
    //can only call this one
    virtual void Draw() override;
};

#endif