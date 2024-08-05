#ifndef ELIPSE_H
#define ELIPSE_H

#include "shape.h"

class Elipse : public Shape{
public:
    Elipse();    
    
    virtual void PrintCount() override{
        std::cout << "There is now: " << count << " instances of Elipse." << std::endl;
    }
    
    static int count;
};

#endif