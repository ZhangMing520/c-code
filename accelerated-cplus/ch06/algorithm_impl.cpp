#include "algorithm_impl.h"
#include <algorithm>
#include <cctype>

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
 * @brief 是否 URL 字符
 *
 * @param c
 * @return true
 * @return false
 */
bool not_url_char(char c)
{
    static const string url_ch = "~;/?:@=&$-_.+!*’(),'";
    // isalnum 字母或者数字
    return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}


/**
 * @brief 识别是否有一个有效的 URL，如果有的话，就返回一个指向相应协议名称的第一个字符的迭代器；
 *       如果它识别不到输入中的 URL，那么它将返回它的第二个变量来指示失败
 *
 * @param b 开始迭代器
 * @param e 结束迭代器
 * @return string::const_iterator
 */
string::const_iterator url_beg(string::const_iterator b, string::const_iterator e)
{
    static const string sep = "://";

    typedef string::const_iterator iter;
    iter i = b;
    while ((i = search(i, e, sep.begin(), sep.end())) != e)
    {
        // 确保分隔符不是本行中唯一的一个符号
        if (i != e && i + sep.size() != e)
        {
            // beg 标记协议名称的开头，往前查找
            // 如果一个容器支持索引，那么它的迭代器也会支持  beg[-1] == *(beg - 1)
            iter beg = i;
            while (beg != b && isalpha(beg[-1]))
                --beg;

            // 至少有一个的有效字符跟在分隔符的后面
            // i[sep.size()] == *(i + sep.size())
            if (beg != i && i + sep.size() != e && !not_url_char(i[sep.size()]))
                return beg;
        }

        // 找到的分隔符不是一个 URL 的一部分，继续往后查找
        if (i != e)
            i += sep.size();
    }
    return e;
}

/**
 * @brief 找出这个 URL 的结尾。这个函数将从给定的位置开始搜索，
 *      直到它到达了输入的结尾或者到达了一个不可能作为 URL 的一部分的字符为止，
 *      然后它会返回一个指向位于这个 URL 的最后一个字符之后的那个位置的迭代器
 *
 * @param b
 * @param e
 * @return string::const_iterator
 */
string::const_iterator url_end(string::const_iterator b, string::const_iterator e)
{
    // 谓词 not_url_char
    return find_if(b, e, not_url_char);
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
        // 获取 URL 开头
        b = url_beg(b, e);
        if (b != e)
        {
            // 获取 URL 结尾
            iter after = url_end(b, e);
            ret.push_back(string(b, after));
            b = after;
        }
    }

    return ret;
}