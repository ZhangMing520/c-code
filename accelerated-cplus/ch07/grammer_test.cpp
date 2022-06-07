/**
 * @file grammer_test.cpp
 * @author your name (you@domain.com)
 * @brief 首先找出一条规则来生成一个句子
 *      种类        规则
 *      <名词>      <cat>
 *      <名词>      <table>
 *      <名词词组>  <名词>
 *      <形容词>    <large>
 *      <动词>      jumps
 *      <位置>      where it wants
 *      <句子>      the <名词词组> <动词> <位置>
 * @version 0.1
 * @date 2022-06-04
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "grammer.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<string> sentence = gen_sentence(read_grammer(cin));
    vector<string>::const_iterator it = sentence.begin();
    if (!sentence.empty())
    {
        cout << *it;
        ++it;
    }

    while (it != sentence.end())
    {
        cout << " " << *it;
        ++it;
    }

    cout << endl;
    return 0;
}