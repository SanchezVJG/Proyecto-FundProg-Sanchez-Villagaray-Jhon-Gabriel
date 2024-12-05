#ifndef __SUM_H__
#define __SUM_H__
#include "values.h"
class mult : public val{
    val mult1;
    val mult2;
    public:
    virtual Complex eval();
};
#endif