#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::string;

int main()
{
    string user_name;
    cout << "Please enter your first name: ";
    cin >> user_name;

    cout << '\n'
         << "Hello, " << user_name << " ... and goodbye!\n";
    return 0;
}