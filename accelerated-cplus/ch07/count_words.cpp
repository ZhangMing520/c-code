/**
 * @file count_words.cpp
 * @author your name (you@domain.com)
 * @brief 统计单词出现次数
 * @version 0.1
 * @date 2022-06-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <map>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;

int main()
{
    string s;
    map<string, int> counters;

    while (cin >> s)
    {
        if (s == "q")
        {
            break;
        }
        ++counters[s];
    }

    for (map<string, int>::const_iterator it = counters.begin(); it != counters.end(); it++)
    {
        cout << it->first << "\t" << it->second << endl;
    }

    return 0;
}