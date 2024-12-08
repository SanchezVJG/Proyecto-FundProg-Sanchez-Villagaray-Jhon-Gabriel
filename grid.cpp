#include <iostream>
#include "complex.h"
using namespace std;

void display(ostream &os,Complex **grid, size_t size){
    for (size_t i =0; i < size ; i++){
        os << "\t" << 'A'+i;
    }
    os << endl;
    for (size_t i = 0; i < size ; i++){
        os << i+1;
        for (size_t j =0; j < size; j++){
            os << "\t" << (grid[i][j]);
        }
        os << endl;
    }
    os << endl;
}
void start(){
    const size_t n=9;
    Complex **grid;
    grid = new Complex*[n];
    for (size_t i =0; i <10 ; i++){
        grid[i] = new Complex[n];
    }
    display(cout,grid,n);
    for (size_t i = 0 ; i < 10 ; i++){
        delete [] grid[i];
    }
    delete [] grid;
}