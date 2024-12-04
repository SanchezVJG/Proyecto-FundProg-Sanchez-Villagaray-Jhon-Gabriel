#ifndef __COMPLEX_H__
#define __COMPLEX_H__
#include <cmath>
using Real = float;
struct Complex{
    Real re=0;
    Real im=0;
};

Complex exp(Complex);
#endif