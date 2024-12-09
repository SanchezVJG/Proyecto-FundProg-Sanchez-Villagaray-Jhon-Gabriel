#include <iostream>
#include "grid.h"
using namespace std;

void display(ostream &os,Complex **grid, size_t size){
    for (size_t i =0; i < size ; i++){
        os << "\t" << char ('A'+i);
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
val *read(const std::string &input){
    size_t found;
    if (input.find_first_of("+-")!=std::string::npos){
        found = input.find_first_of("+-");
        if (input.at(found)=='+'){
            sum *s=nullptr;
            s= new sum;
            s->sum1 = read(input.substr(0,found));
            s->sum2 = read(input.substr(found+1,std::string::npos));
            return s;
        } else {
            dif *r=nullptr;
            r= new dif;
            r->dif1 = read(input.substr(0,found));
            r->dif2 = read(input.substr(found+1,std::string::npos));
            return r;
        }
    } else {
        if (input.find_first_of("*/")!=std::string::npos){
            found = input.find_first_of("*/");
            if (input.at(found)=='*'){
                mult *m = nullptr;
                m= new mult;
                m->mult1 = read(input.substr(0,found));
                m->mult2 = read(input.substr(found+1,std::string::npos));
                return m;
            } else {
                frac *d = nullptr;
                d= new frac;
                d->frac1 = read(input.substr(0,found));
                d->frac2 = read(input.substr(found+1,std::string::npos));
                return d;
            }
        } else {
            num *n=nullptr;
            n= new num;
            n->num = Complex {stof(input),0};
            return n;
        }
    }
}

void start(){
    const size_t n=9;
    Complex **grid;
    grid = new Complex*[n];
    for (size_t i =0; i <10 ; i++){
        grid[i] = new Complex[n];
    }
    val *nodes = nullptr;
    display(cout,grid,n);
    string input;
    getline(cin,input);
    nodes = read(input);
    grid[0][0]= nodes->eval();
    delete nodes;
    display(cout,grid,n);
    for (size_t i = 0 ; i < 10 ; i++){
        delete [] grid[i];
    }
    delete [] grid;
}