#include "algorithm_impl.h"
#include <algorithm>

// 迭代器适配器
using std::back_inserter;
using std::string;
using std::vector;

/**
 * @brief 竖向相加，使用算法库 copy
 *
 * @param top
 * @param bottom
 * @return vector<string>
 */
vector<string> vcat(const vector<string> &top, const vector<string> &bottom)
{
    vector<string> ret;
    copy(bottom.begin(), bottom.end(), back_inserter(ret));
    return ret;
}

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
 * @brief 检查字符串是否回文   eye level
 *
 * @param s
 * @return true
 * @return false
 */
bool is_palindrom(const string &s)
{
    return equal(s.begin(), s.end(), s.rbegin());
}

/**
 * @brief 查找 URL
 *
 * @param s
 * @return vector<string>
 */
vector<string> find_urls(const string &s)
{
    vector<string> ret;
    typedef string::const_iterator iter;
    iter b = s.begin(), e = s.end();

    while (b != e)
    {
        b = url_beg(b, e);
        if (b != e)
        {
            iter after = url_end(b, e);
            ret.push_back(string(b, after));
            b = after;
        }
    }

    return ret;
}

string::const_iterator url_beg(string::const_iterator b, string::const_iterator e)
{
    static const string sep = "://";

    typedef string::const_iterator iter;
    iter i = b;
    while ((i = search(i, e, sep.begin(), sep.end())) != e)
    {
        if(i!=e && i+sep.size () !=e)
        {
            iter beg = i ; 
            while (beg!=b && isalpha(beg[-1]));
            {
                /* code */
            }
            
        }
    }
}
