/**
 * @file count_word_lines_test.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "count_word_lines.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

int main()
{
    map<string, vector<int>> ret = xref(cin);

    for (map<string, vector<int>>::const_iterator it = ret.begin(); it != ret.end(); it++)
    {
        cout << it->first << " occurs on line(s): ";
        
        vector<int>::const_iterator line_it = it->second.begin();
        // 输出第一个行编号，避免末尾有一个多余的逗号
        cout << *line_it;

        ++line_it;
        while (line_it != it->second.end())
        {
            cout << ", " << *line_it;
            ++line_it;
        }
        // 换一个新行
        cout << endl;
    }

    return 0;
}