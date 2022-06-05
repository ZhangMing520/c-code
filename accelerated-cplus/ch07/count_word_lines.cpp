#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "count_word_lines.h"

using std::istream;
using std::map;
using std::string;
using std::vector;

bool space(char c)
{
    return isspace(c);
}

bool not_space(char c)
{
    return !isspace(c);
}

/**
 * @brief find_if 实现 split
 *
 * @param s
 * @return vector<string>
 */
vector<string> split(const string &s)
{
    typedef string::const_iterator iter;
    vector<string> ret;

    iter i = s.begin();
    while (i != s.end())
    {
        i = find_if(i, s.end(), not_space);

        iter j = find_if(i, s.end(), space);
        if (i != s.end())
        {
            ret.push_back(string(i, j));
        }
        i = j;
    }
    return ret;
}

/**
 * @brief 统计单词出现的行数（集合）
 *
 * @param in
 * @param find_words 查找单词的函数指针，缺省值是 split
 * @return map<string, vector<int>>
 */
map<string, vector<int>> xref(istream &in, vector<string> find_words(const string &))
{
    string line;
    int line_number = 0;
    map<string, vector<int>> ret;

    while (getline(in, line))
    {
        if (line == "q")
        {
            break;
        }
        ++line_number;

        vector<string> words = find_words(line);
        for (vector<string>::const_iterator it = words.begin(); it < words.end(); it++)
        {
            ret[*it].push_back(line_number);
        }
    }

    return ret;
}
