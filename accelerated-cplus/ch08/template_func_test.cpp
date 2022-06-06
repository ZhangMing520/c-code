/**
 * @file template_func_test.cpp
 * @author your name (you@domain.com)
 * @brief The only portable way of using templates at the moment is to 
 *      implement them in header files by using inline functions
 * @version 0.1
 * @date 2022-06-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "template_func.h"
#include <vector>
#include <string>
#include <iostream>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;
using std::ostream_iterator;
using std::string;

int main()
{
    string s;
    while (getline(cin, s))
    {
        split(s, ostream_iterator<string>(cout, "\n"));
    }

    return 0;
}