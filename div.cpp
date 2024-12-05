#include "div.h"
Complex div::eval(){
    Complex a= div1.eval();
    Complex b= div2.eval();
    return (a/b);
}