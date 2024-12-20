#ifndef __GRID_H__
#define __GRID_H__
#include <string>
#include "complex.h"
#include "nodes.h"
void display(std::ostream &, Complex **, size_t, size_t);
Node *read(const std::string &, Complex **);
size_t find_noParenth(const std::string &, const std::string &);
bool correctParenth(const std::string &);
void deleteSpaces(std::string &);
void start();
#endif