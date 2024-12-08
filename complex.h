#ifndef __COMPLEX_H__
#define __COMPLEX_H__
#include <iostream>
#include <cmath>
using Real = float;
struct Complex{
    Real re=0;
    Real im=0;
};
Complex operator+(Complex,Complex);
Complex operator*(Complex,Complex);
Complex operator-(Complex);
Complex operator-(Complex,Complex);
Complex abs(Complex);
Complex inv(Complex);
Complex operator/(Complex,Complex);
Complex exp(Complex);
Complex sin(Complex);
Complex cos(Complex);
std::ostream &operator<<(ostream&,Complex&);
#endif