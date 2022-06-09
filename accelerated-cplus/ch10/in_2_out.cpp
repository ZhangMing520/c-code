/**
 * @file in_copy_2_out.cpp
 * @author your name (you@domain.com)
 * @brief in 的文件复制到一个文件名为 out 的文件中
 * @version 0.1
 * @date 2022-06-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <fstream>
#include <string>

using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

int main()
{
    // 文件名定义成字符串常量，或者使用 string 类型 c_str 成员函数 ifstream infile(file.c_str());
    ifstream infile("in");
    ofstream outfile("out");

    string s;
    while (getline(infile, s))
    {
        outfile << s << endl;
    }

    return 0;
}
