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
val *read(const std::string &input,Complex **grid){
    size_t found;
    if (input.find_first_of("+-")!=std::string::npos){
        found = input.find_first_of("+-");
        if (input.at(found)=='+'){
            sum *s=nullptr;
            s= new sum;
            s->sum1 = read(input.substr(0,found),grid);
            s->sum2 = read(input.substr(found+1,std::string::npos),grid);
            return s;
        } else {
            dif *r=nullptr;
            r= new dif;
            r->dif1 = read(input.substr(0,found),grid);
            r->dif2 = read(input.substr(found+1,std::string::npos),grid);
            return r;
        }
    } else {
        if (input.find_first_of("*/")!=std::string::npos){
            found = input.find_first_of("*/");
            if (input.at(found)=='*'){
                mult *m = nullptr;
                m= new mult;
                m->mult1 = read(input.substr(0,found),grid);
                m->mult2 = read(input.substr(found+1,std::string::npos),grid);
                return m;
            } else {
                frac *d = nullptr;
                d= new frac;
                d->frac1 = read(input.substr(0,found),grid);
                d->frac2 = read(input.substr(found+1,std::string::npos),grid);
                return d;
            }
        } else {
            num *n=nullptr;
            n= new num;
            if (input.size()==2 && isalpha(input.at(0))!=0){
                n->num = grid[input.at(1)-'1'][input.at(0)-'A'];
            } else {
                if (input.compare("i") == 0){
                    n->num = Complex {0,1};
                } else {
                    n->num = Complex {stof(input),0};
                }
            }
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
    size_t targetC=0;
    size_t targetN=0;
    for (;;){
        display(cout,grid,n);
        string input;
        cin>>input;
        if (input == "end"){
            break;
        }
        targetC=input.at(0)-'A';
        targetN=input.at(1)-'1';
        nodes = read(input.substr(input.find("=")+1,std::string::npos),grid);
        grid[targetN][targetC]= nodes->eval();
    }
    delete nodes;
    for (size_t i = 0 ; i < 10 ; i++){
        delete [] grid[i];
    }
    delete [] grid;
    cout << "Finished" << endl;
    return;
}