#ifndef GUARD_algorithm_impl_h
#define GUARD_algorithm_impl_h
#include <vector>
#include <string>

std::vector<std::string> vcat(const std::vector<std::string> &, const std::vector<std::string> &);

std::vector<std::string> split(const std::string &);

bool is_palindrom(const std::string &);

std::vector<std::string> find_urls(const std::string &s);

bool not_url_char(char c);

#endif