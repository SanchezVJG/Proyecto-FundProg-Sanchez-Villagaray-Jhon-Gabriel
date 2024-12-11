#ifndef __GRID_H__
#define __GRID_H__
#include <string>
#include "complex.h"
#include "values/values.h"
#include "values/sum.h"
#include "values/res.h"
#include "values/mult.h"
#include "values/div.h"
#include "values/num.h"
#include "values/functions.h"
void display(std::ostream &os,Complex **grid, size_t size);
val *read(const std::string &input ,Complex **grid);
size_t find_nobrack(const std::string &,const std::string &);
void start();
#endif