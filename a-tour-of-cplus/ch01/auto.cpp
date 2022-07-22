#include <iostream>

using std::cout;
using std::endl;

int main()
{
    auto b = true;
    auto ch = 'x';
    auto i = 123;
    auto d = 1.2;
    auto bb{true};
    cout << "b: " << b << ", ch: " << ch << ", i: " << i << ", d: " << d << ", bb: " << bb << endl;
    return 0;
}