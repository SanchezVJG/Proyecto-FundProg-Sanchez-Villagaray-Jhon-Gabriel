#ifndef __GRID_H__
#define __GRID_H__
#include <string>
#include "complex.h"
#include "values.h"
#include "sum.h"
#include "res.h"
#include "mult.h"
#include "div.h"
#include "num.h"
#include "functions.h"
void display(std::ostream &os,Complex **grid, size_t size);
val *read(const std::string &input ,Complex **grid);
size_t find_nobrack(const std::string &,const std::string &);
void start();
#endif