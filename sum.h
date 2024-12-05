#ifndef __SUM_H__
#define __SUM_H__
#include "values.h"
class sum : public val{
    val sum1;
    val sum2;
    public:
    virtual ~sum();
    virtual Complex eval();
};
#endif