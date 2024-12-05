#include <iostream>
#include "complex.h"
using namespace std;

Complex operator+(Complex &C1,Complex &C2){
    return Complex {{C1.re+C2.re},{C1.im+C2.im}};
}

Complex operator*(Complex &C1,Complex &C2){
    return Complex {{C1.re*C2.re-C1.im*C2.im},{C1.re*C2.im+C1.im*C2.re}};
}

Complex exp(Complex &C){
    return Complex {{C.re*cos(C.im)},{C.re*sin(C.im)}};
}

ostream &operator<<(ostream &os, Complex &C){
    os << C.re;
    if (C.im >0)
    os << "+";
    if (C.im !=0)
    os << C.im << "*i";
    return os;
}