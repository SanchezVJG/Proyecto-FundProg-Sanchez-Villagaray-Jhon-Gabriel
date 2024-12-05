#ifndef __NUM_H__
#define __NUM_H__
#include "values.h"
class num : public val{
    Complex num1;
    public:
    virtual ~num();
    virtual Complex eval();
};
#endif