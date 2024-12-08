#include <iostream>
#include "complex.h"
using namespace std;

Complex operator+(Complex C1,Complex C2){
    return Complex {C1.re+C2.re,C1.im+C2.im};
}

Complex operator-(Complex C1, Complex C2){
    return C1+(-C2);
}
Complex operator-(Complex C){
    return Complex {-C.re,-C.im};
}

Complex operator*(Complex C1,Complex C2){
    return Complex {C1.re*C2.re-C1.im*C2.im,C1.re*C2.im+C1.im*C2.re};
}

Complex abs(Complex C){
    return Complex {sqrt(C.re*C.re+C.im*C.im),0};
}

Complex inv(Complex C){
    Real abs2 = (C.re*C.re+C.im*C.im);
    return Complex { C.re/(abs2) , -C.im/(abs2) };
}

Complex operator/(Complex C1, Complex C2){
    Complex in = inv(C2);
    return (C1*in);
}

Complex exp(Complex C){
    return Complex {{exp(C.re)*cos(C.im)},{exp(C.re)*sin(C.im)}};
}
Complex sin(Complex C){
    return (exp(Complex {0,1}*C)-exp(Complex {0,-1}*C))/Complex {0,2};
}
Complex cos(Complex C){
    return (exp(Complex {0,1}*C)+exp(Complex {0,-1}*C))/Complex {2,0};
}

ostream &operator<<(ostream &os, Complex &C){
    os << C.re;
    if (C.im >0)
    os << "+";
    if (C.im !=0)
    os << C.im << "*i";
    return os;
}