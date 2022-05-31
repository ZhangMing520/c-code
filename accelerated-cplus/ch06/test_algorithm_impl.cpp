#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using std::copy;
using std::string;
using std::vector;
// 迭代器适配器
using std::back_inserter;

string::const_iterator url_end(string::const_iterator, string::const_iterator);


bool not_url_char(char c)
{
    static const string url_ch = "~;/?:@=&$-_.+!*'(),'";
    return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_end());
}

string::const_iterator url_end(string::const_iterator b, string::const_iterator e)
{
    return find_if(b, e, not_url_char);
}