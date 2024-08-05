#ifndef STREAM_H
#define STREAM_H

#include <iostream>

class StreamInsertable{
    friend std::ostream& operator << (std::ostream& out, const StreamInsertable& operand);
    
    public:
        virtual void StreamInsert(std::ostream& out) const =0;
};

#endif