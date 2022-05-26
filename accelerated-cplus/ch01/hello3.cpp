#include <iostream>
#include <string>

using namespace std;

/**
 * @brief 一次性输入2个名字Samuel Beckett，程序会以空白分隔，读入2次
 * @return ** int 
 */
int main()
{
    cout << "What is your name? ";
    string name;
    cin >> name;

    cout << "Hello, " << name << endl
         << "And what is yours? ";
    cin >> name;
    cout << "Hello, " << name << "; nice to meet to you!" << endl;

    return 0;
}