#include "count_word_lines.h"
#include "grammer.h"
#include <stdexcept>
#include <cstdlib>

using std::domain_error;
using std::istream;
using std::logic_error;
using std::map;
using std::string;
using std::vector;

Grammer
read_grammer(istream &in)
{
    Grammer ret;
    string line;
    while (getline(in, line))
    {
        vector<string> entry = split(line);

        if (!entry.empty())
        {
            // 第一个元素是种类，规则从第二个元素开始
            ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
        }
    }
}

/**
 * @brief 根据规则生成句子
 * 
 * @param g 
 * @return vector<string> 
 */
vector<string> gen_sentence(const Grammer &g)
{
    vector<string> ret;

    gen_aux(g, "<sentence>", ret);
    return ret;
}

/**
 * @brief 必须判断一个单词是不是代表了一个种类，需要检查这个单词是否括起
 *
 * @param s
 * @return true
 * @return false
 */
bool bracketed(const string &s)
{
    return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

/**
 * @brief 返回 [0,n) 随机数
 *      假设 RAND_MAX=32767 n=100，那么随机数被分成100份长度精确相同的存储通（但是也存在随机数没有进入到任何的存储桶）；
 *      所以反复请求随机数，直到获得一个合适的为止 
 * 
 *      rand()%n 
 *      1. rand() 返回的只是伪随机数。当商是小整数的时候，许多 C++ 系统环境的伪随机数生成器所产生的余数并不是绝对随机的。
 *      如果 n=2，那么 rand()%n 的逐次结果就将在0和1之间选择（其实结果并没有错误，只是不随机，轮着来）
 * 
 *      2. 如果 n 的值很大，那么 RAND_MAX 就不会均匀的被 n 除尽，一些余数出现的频率将会比其他的更加大
 *      假设 RAND_MAX=32767 n=20000，那么 rand() 将会有2个值能令 rand()%n=10000，也就是 10000 和 30000；
 *      但是rand()%n=15000，只有 15000。因此简单实现产生 10000 的概率将会是它产生 15000 的概率的两倍。
 *              
 * 
 * @param n 是远小于RAND_MAX的
 * @return int 
 */
int nrand(int n)
{
    if (n <= 0 || n > RAND_MAX)
        throw domain_error("Argument to nrand is out of range");

    const int bucket_size = RAND_MAX / n;
    int r;

    do
        r = rand() / bucket_size;
        // [0,n) 随机数
    while (r >= n);

    return r;
}

/**
 * @brief 如果某一个元素有括号括起，那我们就必须把它展开为一系列的单词；否则，把它添加到 ret 中
 *
 * @param g
 * @param word
 * @param ret
 */
void gen_aux(const Grammer &g, const string &word, vector<string> &ret)
{
    if (!bracketed(word))
    {
        // 非规则，只是单词
        ret.push_back(word);
    }
    else
    {
        // 定位规则
        Grammer::const_iterator it = g.find(word);
        if (it == g.end())
            throw logic_error("empty rule");
        // 获取可能的规则集合
        const Rule_collection &c = it->second;
        // 从规则集合中随机选择一条规则
        const Rule &r = c[nrand(c.size())];
        // 递归展开所选定的规则
        for (Rule::const_iterator i = r.begin(); i != r.end(); i++)
        {
            gen_aux(g, *i, ret);
        }
    }
}