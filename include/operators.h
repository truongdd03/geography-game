#ifndef OPERATORS_H
#define OPERATORS_H

#include <string>
#include <vector>

void clear();

void write(std::string const &);

void addParams(std::vector<std::string> const &);

void Or(std::string, std::vector<std::string> const &);

void And(std::string, std::vector<std::string> const &);

void Exists(std::vector<std::string> const &);

void Forall(std::vector<std::string> const &);

#endif
