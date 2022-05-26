#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::streamsize;
using std::string;

int main()
{
    cout << "Please enter you first name: ";
    string name;
    cin >> name;
    cout << "Hello, " + name << "!" << endl;

    cout << "Please enter you midterm and final exam grades: ";
    double midterm, finals;
    cin >> midterm >> finals;

    // 空白符分隔，字符串直接量会被自动连接到一起
    cout << "Enter all your homework grades, "
            "followed by end-of-file: ";
    int count = 0;
    double sum = 0;

    double x;
    // 输入文件的结尾
    // 输入可能跟读取的变量的类型不一致
    // 输入装置中检测到一个硬件问题
    // 100 90 100 d
    while (cin >> x)
    {
        ++count;
        sum += x;
    }

    // 把精度设置为3，并返回原先的精度
    // streamsize prec = cout.precision(3);
    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3)
         << 0.2 * midterm + 0.4 * finals + 0.4 * sum / count << setprecision(prec) << endl;

    return 0;
}