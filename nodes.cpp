#include "nodes.h"
Node::~Node(){}
Complex Node::eval(){return Complex{0, 0};}


constNode::constNode(const Complex& num){}
Complex constNode::eval(){return num;}

unNode::~unNode(){delete num;}

unNode::unNode(const Node* num = nullptr,const size_t &index=0){}

Complex unNode::eval(){return (op.*opp[index])(num->eval());}
void unNode::set(const Node* num){}
void unNode::seti(const size_t& index){}


biNode::~biNode(){delete num1;delete num2;}

biNode::biNode(const Node* num1, const Node* num2, const size_t &index){}

Complex biNode::eval(){return (op.*opp[index])(num1->eval(),num2->eval());}
void biNode::set1(const Node* num1){}
void biNode::set2(const Node* num2){}
void biNode::seti(const size_t& index){}


Complex unOperations::exp(const Complex &C){return exp(C);}
Complex unOperations::sine(const Complex &C){return sin(C);}
Complex unOperations::cosine(const Complex &C){return cos(C);}
Complex unOperations::abs(const Complex &C){return abs(C);}
Complex unOperations::ln(const Complex &C){return ln(C);}

Complex biOperations::sum(const Complex &C1,const Complex &C2){return C1+C2;}
Complex biOperations::res(const Complex &C1,const Complex &C2){return C1-C2;}
Complex biOperations::mult(const Complex &C1,const Complex &C2){return C1*C2;}
Complex biOperations::div(const Complex &C1,const Complex &C2){return C1/C2;}