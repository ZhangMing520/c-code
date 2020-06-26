//
// Created by zhangming on 2020/6/22.
//

// rvalue 和 lvalue reference 重载规则

// 由下面推出：如果class未提供move语义，只提供常用的 copy 构造函数和 copy assignment 操作符， rvalue reference 可以调用他们
// std::move() 意味着“调用move语义（有提供的话），否则调用copy语义”

#include <iostream>
#include <utility>

class X {

};

//  foot(x) 可以 foo(std::move(x)) 不行
//void foo(X &);

//  foot(x) 可以 foo(std::move(x)) 可以
//void foo(const X &);

// foot(x) 不行 foo(std::move(x)) 可以
void foo(X &&);

int main() {
    X x;
    foo(std::move(x));
//    foo(std::move(x));

    return 0;
}

void foo(X &) {
    std::cout << "X&" << std::endl;
}

void foo(const X &) {
    std::cout << "const X&" << std::endl;
}

void foo(X &&) {
    std::cout << "X&&" << std::endl;
}
