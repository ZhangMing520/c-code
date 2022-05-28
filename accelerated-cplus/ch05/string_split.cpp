#include "string_split.h"
#include <algorithm>

using std::max;
using std::string;
using std::vector;

/**
 * @brief 字符串也是容器
 *
 * @param s
 * @return vector<string>
 */
vector<string> split(const string &s)
{
    vector<string> ret;
    typedef string::size_type string_size;
    string_size i = 0;

    while (i != s.size())
    {
        while (i != s.size() && isspace(s[i]))
            ++i;

        string_size j = i;
        while (j != s.size() && !isspace(s[j]))
            ++j;

        if (i != j)
        {
            // 从 i 开始复制 j-i 个字符
            ret.push_back(s.substr(i, j - i));
            i = j;
        }
    }
    return ret;
}

/**
 * @brief   找出向量中最长的字符串的长度
 *
 * @param v
 * @return string::size_type
 */
string::size_type width(const vector<string> &v)
{
    string::size_type maxlen = 0;
    for (string::size_type i = 0; i != v.size(); i++)
    {
        maxlen = max(maxlen, v[i].size());
    }
    return maxlen;
}

/**
 * @brief 给 vector 边框
 *
 * @param v
 * @return vector<string>
 */
vector<string> frame(const vector<string> &v)
{
    vector<string> ret;
    string::size_type maxlen = width(v);
    string border(maxlen + 4, '*');

    ret.push_back(border);

    for (vector<string>::size_type i = 0; i != v.size(); i++)
    {
        ret.push_back("* " + v[i] + string(maxlen - v[i].size(), ' ') + " *");
    }

    ret.push_back(border);
    return ret;
}

/**
 * @brief 竖向相加
 *
 * @param top
 * @param bottom
 * @return vector<string>
 */
vector<string> vcat(const vector<string> &top, const vector<string> &bottom)
{
    vector<string> ret = top;
    ret.insert(ret.end(), bottom.begin(), bottom.end());
    return ret;
}

/**
 * @brief 横向相加
 *
 * @param left
 * @param right
 * @return vector<string>
 */
vector<string> hcat(const vector<string> &left, const vector<string> &right)
{
    vector<string> ret;

    string::size_type widthl = width(left) + 1;
    vector<string>::size_type i = 0, j = 0;

    while (i != left.size() || j != right.size())
    {
        string s;
        if (i != left.size())
            s = left[i++];

        s += string(widthl - s.size(), ' ');

        if (j != right.size())
            s += right[j++];

        ret.push_back(s);
    }

    return ret;
}