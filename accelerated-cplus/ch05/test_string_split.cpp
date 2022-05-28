/**
 * @file test_string_split.cpp
 * @author zhangming (you@domain.com)
 * @brief 测试 string_split
 *          g++ *string_split*.cpp *string_split*.h -o  test_string_split
 *          ./test_string_split
 *
 * @version 0.1
 * @date 2022-05-28
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "string_split.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    // test split
    // string s;
    // while (getline(cin, s))
    // {
    //     vector<string> v = split(s);

    //     for (vector<string>::size_type i = 0; i != v.size(); i++)
    //     {
    //         cout << v[i] << endl;
    //     }
    // }

    // test frame
    // vector<string> sv = {"this is an", "example", "to", "illustrate", "framing"};
    // vector<string> v = frame(sv);
    // for (vector<string>::size_type i = 0; i != v.size(); i++)
    // {
    //     cout << v[i] << endl;
    // }

    // test vcat
    // vector<string> top = {"this is an", "example", "to", "illustrate", "framing"};
    // vector<string> bottom = {"this is an", "example", "to", "illustrate", "framing!!!!!!!!"};
    // vector<string> v = vcat(frame(top), frame(bottom));
    // for (vector<string>::size_type i = 0; i != v.size(); i++)
    // {
    //     cout << v[i] << endl;
    // }

    // test hcat
    vector<string> left = {"this is an", "example", "to", "illustrate", "framing"};
    vector<string> right = {"hello", "world", "this is an", "example", "to", "illustrate", "framing!!!!!!!!"};
    vector<string> v = hcat(frame(left), frame(right));
    for (vector<string>::size_type i = 0; i != v.size(); i++)
    {
        cout << v[i] << endl;
    }

    return 0;
}