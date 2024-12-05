#include "sum.h"
Complex sum::eval(){
    Complex a= sum1.eval();
    Complex b= sum2.eval();
    return (a+b);
}