#ifndef __MULT_H__
#define __MULT_H__
#include "values.h"
class mult : public val{
    val mult1;
    val mult2;
    public:
    virtual ~mult();
    virtual Complex eval();
};
#endif