#include <iostream>
#include <string>

using namespace std;

int main()
{

    const size_t height = 4;
    const size_t width = 4;
    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            cout << '*';
        }
        cout << endl;
    }

    // 直角三角形
    cout << endl;
    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            if (j <= i)
            {
                cout << '*';
            }
        }
        cout << endl;
    }

    // 等腰三角形
    cout << endl;
    for (size_t i = 1; i <= height; i++)
    {
        for (size_t j = 1; j <= height - i; j++)
        {
            cout << ' ';
        }
        // 右边不一定需要打印，空白就行
        for (size_t j = 1; j <= i * 2 - 1; j++)
        {
            cout << '*';
        }
        cout << endl;
    }

    return 0;
}