//
// Created by zhangming on 2020/6/21.
//

// nullptr 取代0或者NULL，用来表示一个指针指向所谓的no value (不同于拥有一个不确定的值)
// 避免误解：null pointer 解释为一个整数值

#include <iostream>

void f(int);

void f(int *);

int main() {
    f(0);
    // error ambiguous
    //f(NULL);
    f(nullptr);

    return 0;
}

void f(int a) {
    std::cout << a << std::endl;
    std::cout << "f(int)" << std::endl;
}

void f(int *a) {
    std::cout << a << std::endl;
    std::cout << "f(int*)" << std::endl;
}