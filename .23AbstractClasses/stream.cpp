#include "stream.h"

std::ostream& operator<< (std::ostream& out, const StreamInsertable& operand){
    operand.StreamInsert(out);
    return out;
}