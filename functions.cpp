#include "functions.h"
expo::~expo(){
    delete input;
}

Complex expo::eval(){
    return (exp(input->eval()));
}

sine::~sine(){
    delete input;
}

Complex sine::eval(){
    return (sin(input->eval()));
}

cosine::~cosine(){
    delete input;
}

Complex cosine::eval(){
    return (cos(input->eval()));
}