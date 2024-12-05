#include "mult.h"
Complex mult::eval(){
    Complex a= mult1.eval();
    Complex b= mult2.eval();
    return (a*b);
}