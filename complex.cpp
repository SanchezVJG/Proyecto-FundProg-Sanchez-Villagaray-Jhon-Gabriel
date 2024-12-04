#include <iostream>
#include "complex.h"
using namespace std;

Complex operator+(Complex C1,Complex C2){
    return Complex {{C1.re+C2.re},{C1.im+C2.im}};
}