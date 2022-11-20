#ifndef OPERATORS_H
#define OPERATORS_H

#include <string>
#include <vector>

void clear();

void write(std::string const &);

void addParams(std::vector<std::string> const &);

void Or(int, std::vector<std::string> const &);

void And(int, std::vector<std::string> const &);

#endif
