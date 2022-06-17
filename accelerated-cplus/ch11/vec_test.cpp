#include "vec.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main()
{
    Vec<string> v;
    v.push_back("hello");
    cout << "size: " << v.size() << endl;
    for (Vec<string>::const_iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
