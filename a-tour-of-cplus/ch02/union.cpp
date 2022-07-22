/**
 * @file union.cpp
 * @author your name (you@domain.com)
 * @brief   union是一种特殊的struct, 它的所有成员被分配在同一内存区域中。
 * @version 0.1
 * @date 2022-07-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <string>
#include <iostream>

enum Type
{
    ptr,
    num
};

struct Node
{
};

union Value
{
    Node *p;
    int i;
};

struct Entry
{
    std::string name;
    Type t;
    Value v;
};

void f(Entry *e)
{
    if (e->t == num)
    {
        std::cout << e->v.i;
        // ...
    }
}
