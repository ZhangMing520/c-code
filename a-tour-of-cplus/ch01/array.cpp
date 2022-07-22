#include <iostream>

using std::cout;

void copy_fct();
void print();

int main()
{   
    copy_fct();
    print();
    return 0;
}

void copy_fct()
{
    int v1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int v2[10];

    for (auto i = 0; i != 10; i++)
    {
        v2[i] = v1[i];
    }

    for (auto i : v2)
    {
        cout << i << '\n';
    }
}

void print()
{
    int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (auto x : v)
    {
        cout << x << '\n';
    }
    for (auto x : {10, 21, 32, 43, 54, 65})
    {
        cout << x << '\n';
    }
}