#include <fstream>
/**
 * @file ins_2_out.cpp
 * @author your name (you@domain.com)
 * @brief 读取多个文件
 * @version 0.1
 * @date 2022-06-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <string>
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

int main(int argc, char **argv)
{
    int fail_count = 0;

    for (size_t i = 1; i < argc; i++)
    {
        ifstream in(argv[i]);
        if (in)
        {
            string s;
            while (getline(in, s))
            {
                cout << s << endl;
            }
        }
        else
        {
            // 文件不存在，或者不能打开等原因
            cerr << "cannot open file" << argv[i] << endl;
            ++fail_count;
        }
    }

    return 0;
}