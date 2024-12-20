#ifndef __NODES_H__
#define __NODES_H__
#include "complex.h"
class Node
{
public:
    virtual ~Node();
    virtual Complex eval()=0;
};

class constNode : public Node {
    Complex num;
    
    public:
    constNode(const Complex&);
    void set(const Complex&);
    virtual Complex eval();
};

class unNode : public Node{
    Node *num;
    size_t index;
    unOperations op;
    Complex (unOperations:: *opp[5])(const Complex&) ={unOperations::exp,unOperations::sine,unOperations::cosine,unOperations::abs,unOperations::ln};
    virtual ~unNode();

    public:
    unNode(const Node*,const size_t&);
    void set(const Node*);
    void seti(const size_t&);
    virtual Complex eval();
};

class biNode : public Node{
    Node *num1;
    Node *num2;
    size_t index;
    biOperations op;
    Complex (biOperations:: *opp[4])(const Complex&,const Complex&)={biOperations::sum,biOperations::res,biOperations::mult,biOperations::div};
    virtual ~biNode();
    virtual Complex eval();

    public:
    biNode(const Node*,const Node*, const size_t&);
    void set1(const Node*);
    void set2(const Node*);
    void seti(const size_t&);
};

struct unOperations{
    Complex exp(const Complex&);
    Complex sine(const Complex&);
    Complex cosine(const Complex&);
    Complex abs(const Complex&);
    Complex ln(const Complex&);
};

struct biOperations{
    Complex sum(const Complex&,const Complex&);
    Complex res(const Complex&,const Complex&);
    Complex mult(const Complex&,const Complex&);
    Complex div(const Complex&,const Complex&);
};
#endif