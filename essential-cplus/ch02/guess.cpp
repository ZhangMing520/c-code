#include <iostream>

using std::cin;
using std::cout;
using std::endl;

bool fibon_elem(int, int &);

int main()
{
    int pos;
    cout << "Please enter a position: ";
    cin >> pos;

    int elem;
    if (fibon_elem(pos, elem))
    {
        cout << "element # " << pos << " is " << elem << endl;
    }
    else
    {
        cout << "Sorry, Could not calculate element #" << pos << endl;
    }

    return 0;
}

bool fibon_elem(int pos, int &elem)
{
    if (pos <= 0 || pos > 1024)
    {
        elem = 0;
        return false;
    }
    elem = 1;
    int n_2 = 1, n_1 = 1;
    for (int i = 3; i <= pos; i++)
    {
        elem = n_1 + n_2;
        n_2 = n_1;
        n_1 = elem;
    }
    return true;
}