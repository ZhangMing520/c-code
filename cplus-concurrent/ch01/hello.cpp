#include <iostream>
#include <thread>

using std::cin;
using std::cout;
using std::thread;

void hello();

int main()
{
    thread t(hello);
    t.join();
    return 0;
}

void hello()
{
    cout << "Hello Concurrent World\n";
}