/**
 * @file union2.cpp
 * @author your name (you@domain.com)
 * @brief   标记联合。将联合和类型域封装在一个类中、只允许通过能正确使用联合的成员函数来访问他们。
 * @version 0.1
 * @date 2022-07-20
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <variant>
#include <string>
#include <iostream>

using std::cout;
using std::get;
using std::holds_alternative;
using std::string;
using std::variant;

enum Type
{
    ptr,
    num
};

struct Node
{
};

struct Entry
{
    string name;
    variant<Node *, int> v;
};

void f(Entry *e)
{
    // e 保存了int吗
    if (holds_alternative<int>(e->v))
    {
        // 获取一个int
        cout << get<int>(e->v);
    }
}
