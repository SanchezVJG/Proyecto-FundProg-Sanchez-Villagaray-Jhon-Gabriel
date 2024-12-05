#ifndef __COMPLEX_H__
#define __COMPLEX_H__
#include <cmath>
using Real = float;
struct Complex{
    Real re=0;
    Real im=0;
};
Complex operator+(Complex&,Complex&);
Complex operator*(Complex&,Complex&);
Complex abs(Complex&);
Complex operator/(Complex&,Complex&);
Complex exp(Complex&);
#endif