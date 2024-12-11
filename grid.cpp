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
size_t find_nobrack(const std::string &str,const string &characters){
    size_t inception=0;
    for (size_t i = 0; i< str.size() ;i++){
        if(str.at(i)=='(')
        inception++;
        if(str.at(i)==')')
        inception--;
        if(characters.find(str.at(i)) != std::string::npos && inception ==0){
            return i;
        }
    }
    return std::string::npos;
}

val *read(const std::string &input,Complex **grid){
    size_t found;
    string reduced = input;
    for (;;){
        found =find_nobrack(reduced,"+-");
        if (found!=std::string::npos){
            if (reduced.at(found)=='+'){
                sum *s=nullptr;
                s= new sum;
                s->sum1 = read(reduced.substr(0,found),grid);
                s->sum2 = read(reduced.substr(found+1,std::string::npos),grid);
                return s;
            } else {
                dif *r=nullptr;
                r= new dif;
                r->dif1 = read(reduced.substr(0,found),grid);
                r->dif2 = read(reduced.substr(found+1,std::string::npos),grid);
                return r;
            }
        } else {
            found =find_nobrack(reduced,"*/");
            if (found!=std::string::npos){
                if (reduced.at(found)=='*'){
                    mult *m = nullptr;
                    m= new mult;
                    m->mult1 = read(reduced.substr(0,found),grid);
                    m->mult2 = read(reduced.substr(found+1,std::string::npos),grid);
                    return m;
                } else {
                    frac *d = nullptr;
                    d= new frac;
                    d->frac1 = read(reduced.substr(0,found),grid);
                    d->frac2 = read(reduced.substr(found+1,std::string::npos),grid);
                    return d;
                }
            } else {
                if (reduced.at(0)=='(' && reduced.at(reduced.size()-1)==')'){
                    reduced = reduced.substr(1,reduced.size()-2);
                } else{
                    if (reduced.substr(0,3)=="sin"){
                        sine *si =nullptr;
                        si = new sine;
                        si->input = read(reduced.substr(3,string::npos),grid);
                        return si;
                    } else {
                        if (reduced.substr(0,3)=="cos"){
                            cosine *co = nullptr;
                            co = new cosine;
                            co->input = read(reduced.substr(3,string::npos),grid);
                            return co;
                        } else {
                            if (reduced.substr(0,2)=="e^"){
                                expo *ex = nullptr;
                                ex = new expo;
                                ex->input = read(reduced.substr(2,string::npos),grid);
                                return ex;
                            } else {
                                num *n=nullptr;
                                n= new num;
                                if (reduced.size()==2 && isalpha(reduced.at(0))!=0){
                                    n->num = grid[reduced.at(1)-'1'][reduced.at(0)-'A'];
                                } else {
                                    if (reduced.at(0)=='i'){
                                        n->num = Complex {0,1};
                                    } else {
                                        n->num = Complex {stof(reduced),0};
                                    }
                                }
                                return n;
                            }
                        }
                    }
                }
            }
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
        display(std::cout,grid,n);
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