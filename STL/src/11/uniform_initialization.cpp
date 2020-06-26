//
// Created by zhangming on 2020/6/21.
//

// 一致性初始化
// 面对任务初始化动作，你可以使用相同语法，也就是大括号

// 初值列  initializer list
// 会强迫造成所谓 value initialization，意思是即使某个local变量属于某种基础类型（通常会有不明确的初值）
// 也会被初始化为0或nullptr

// 窄化（narrowing）
// 精度降低或造成数值变动 -- 对大括号不成立

// 用户自定义类型值初值列 initializer lists for user-defined types
// std::initializer_list 支持一系列值初始化或者在“你想要处理一系列值”的任何地点进行初始化

// 当“指明实参个数”和“指明一个初值列”的额构造函数同时存在，带有初值列的版本胜出

// explicit 会导致“多数值自动类型转换”不再起作用，即使初始化以=语法进行

#include <vector>
#include <string>
#include <complex>
#include <iostream>

void print(std::initializer_list<int> vals);

class P {
public:
    P(int, int) {
        std::cout << "(int,int)" << std::endl;
    }

    P(std::initializer_list<int>) {
        std::cout << "initializer_list<int>" << std::endl;
    }
};

class Q {
public:

    Q(int, int) {
        std::cout << "(int,int)" << std::endl;
    }

    // explicit 不允许隐式自动转化
    explicit Q(int, int, int) {
        std::cout << "(int,int,int)" << std::endl;
    }
};

int main() {

    ////////////////  一致性初始化

    int value[]{1, 2, 3};
    std::vector<int> v{2, 3, 4, 5, 6, 6};
    std::vector<std::string> cities{
            "Berlin", "New York", "London", "Cairo"
    };
    std::complex<double> c{4.0, 3.0};  // (4.0,3.0)

    //////////////////  初值列
    int i;   // has undefined value
    int j{};  // initialized by 0
    int *p;    // has undefined value
    int *q{};  // initialized by nullptr

    ////////// 窄化（narrowing）
    int x1(5.3);  // x1 becomes 5
    int x2 = 5.3; // x2 becomes 5

    // error narrowing
//    int x3{5.0};
//    int x4 = {5.4};

    char c1{7};
    // error narrowing
//    char c2{9999};

    std::vector<int> v1{1, 2, 3, 4};
    // error
    // std::vector<int> v2{1,2.3,4};

    ////////////////// 用户自定义类型值初值列
    print({1, 1, 2, 3, 4, 5, 89});

    //////////////////// 优先带有初值列的版本构造函数
    P x(77, 5);  // (int,int)
    P y{77, 5};  // initializer_list<int>
    P r{77, 5, 43};  // initializer_list<int>
    P s = {77, 5, 43};  // initializer_list<int>

    /////////////////////// explicit
    // error due to explicit
    Q m(77,5);
    Q n{77,5};
    Q z{77,5,2};
    //Q w = {77, 5, 43};  // initializer_list<int>

    return 0;
}

void print(std::initializer_list<int> vals) {
    for (auto p = vals.begin(); p != vals.end(); ++p) {
        std::cout << *p << " ";
    }
    std::cout << std::endl;
}
