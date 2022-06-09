/**
 * @file say.cpp
 * @author your name (you@domain.com)
 * @brief argv 数组的首元素总是 main 函数编译后的程序名，所以 argc 的值至少是1
 * @version 0.1
 * @date 2022-06-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        size_t i;
        for (i = 1; i < argc - 1; i++)
        {
            cout << argv[i] << " ";
        }
        // 最后一个参数，后面没有空格
        cout << argv[i] << endl;
    }
    return 0;
}