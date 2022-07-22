#include <iostream>
#include <complex>
#include <vector>

using std::complex;
using std::cout;
using std::vector;

int main()
{
    cout << "Hello, World\n";
    // 单引号作为数字分隔符 c++17
    cout << 3.141'592 << "\n";

    // {} 花括号初始化，=是可选的
    double d1 = 2.3;
    double d2{2.3};
    double d3 = {2.3};
    complex<double> z = 1;
    complex<double> z2{d1, d2};
    complex<double> z3 = {d1, d2};

    vector<int> v{1, 2, 3, 4, 5, 6};
}