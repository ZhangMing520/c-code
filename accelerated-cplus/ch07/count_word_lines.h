#ifndef GUARD_count_word_lines_h
#define GUARD_count_word_lines_h

#include <map>
#include <string>
#include <vector>
#include <iostream>

std::vector<std::string> split(const std::string &);

// 头文件声明了参数默认值，cpp实现的时候，就不需要声明默认值了，否则编译报错
std::map<std::string, std::vector<int>> xref(std::istream &,
                                             std::vector<std::string> find_words(const std::string &)= split);

#endif