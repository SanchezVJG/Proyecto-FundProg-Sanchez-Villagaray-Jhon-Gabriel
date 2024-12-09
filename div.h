#ifndef __DIV_H__
#define __DIV_H__
#include "values.h"
class div : public val{
    val div1;
    val div2;
    public:
    virtual Complex eval();
};
#endif