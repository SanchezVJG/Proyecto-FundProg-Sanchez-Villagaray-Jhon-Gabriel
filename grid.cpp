#include <iostream>
#include "complex.h"
using namespace std;

void start(){
    const size_t n=9;
    Complex **grid;
    grid = new Complex*[n];
    for (size_t i =0; i <10 ; i++){
        grid[i] = new Complex[n];
    }
    for (size_t i = 0 ; i < 10 ; i++){
        delete [] grid[i];
    }
    delete [] grid;
}