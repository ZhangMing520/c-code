#include <thread>
#include <iostream>

using std::cout;
using std::thread;

void f()
{
    cout << "Hello ";
}

struct F
{
    void operator()()
    {
        cout << "Parallel World\n";
    };
};

int main()
{
    thread t1{f};
    thread t2{F()};

    t1.join();
    t2.join();
}