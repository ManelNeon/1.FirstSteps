#ifndef CAT_H
#define CAT_H

#include "animal.h"

//by putting the final keyword on Cat, there's no way a function can derive from it, Cat is the final nail in the coffin
class Cat final: public Animal{
public:
    void Meow();
};

//this gives us an error, because cat is final
/*
class Tiger : public Cat{
    
};
*/

#endif