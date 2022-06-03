#include "algorithm_impl.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    cout << "Please enter a URL str: ";
    string url;
    cin >> url;

    vector<string> ret = find_urls(url);
    for (vector<string>::const_iterator it = ret.begin(); it != ret.end(); it++)
    {
        cout << *it << endl;
    }
    return 0;
}