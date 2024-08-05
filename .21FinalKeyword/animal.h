#ifndef ANIMAL_H
#define ANIMAL_H

class Animal{
public:
    //so as we studied before, the virtual keyword makes it possible for us to override that function in a children class
    //well jump over to dog.h then
    virtual void Breathe();
};

#endif