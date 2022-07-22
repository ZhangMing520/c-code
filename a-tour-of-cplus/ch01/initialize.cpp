#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int x = 2;
    int y = 3;
    int *p = &x;
    int *q = &y;
    // p 变为 &y; p==q ; p和q地址一致
    p = q;
    cout << "p = " << *p << ", q = " << *q << endl;

    int &r = x;
    int &r2 = y;
    // r和r2地址不一致，值一致
    r = r2;
    cout << "r = " << r << ", r2 = " << r2 << endl;

    // 正确
    int &r3{x};

    // 错误：未初始化的引用
    // int &r4;

    return 0;
}