#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Please enter your first name: ";
    string name;
    cin >> name;

    const string greeting = "Hello, " + name + "!";

    // 空白行
    const int pad = 1;
    // 总行数
    const int rows = pad * 2 + 3;
    // 总行数
    const string::size_type cols = greeting.size() + pad * 2 + 2;

    cout << endl;
    int r = 0;
    while (r < rows)
    {
        string::size_type c = 0;
        while (c < cols)
        {
            if (r == pad + 1 && c == pad + 1)
            {
                cout << greeting;
                c += greeting.size();
            }
            else
            {
                if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
                    // 边界字符
                    cout << "*";
                else
                    cout << " ";
                ++c;
            }
        }
        cout << endl;
        r++;
    }

    return 0;
}