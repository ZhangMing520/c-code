#ifndef GUARD_grammer_h
#define GUARD_grammer_h

#include <vector>
#include <string>
#include <iostream>
#include <map>

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, Rule_collection> Grammer;

Grammer read_grammer(std::istream &);

std::vector<std::string> gen_sentence(const Grammer &);

void gen_aux(const Grammer &, const std::string &, std::vector<std::string> &);

#endif