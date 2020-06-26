//
// Created by zhangming on 2020/6/7.
//

// C++ 17配备了一种新的特性 - 结构化绑定，其可以结合语法糖来自动推导类型，并可以从
// 组对，元组和结构体中提取单独的变量。在其他编程语言中，这种特性也被称为解包

// auto [var1, var2, ...] = <pair, tuple, struct, or array expression>;
// auto,const auto,const auto&和auto&&
// 不仅为了性能，还必须确保在适当的时刻使用引用，尽量减少不必要的副本。

//与C的语法特征不同，将复杂结构体作为返回值传回会耗费大量的时间，因为对象需要在返回函数中进行初始化，
//之后将这个对象拷贝到相应容器中返回给调用端。

#include <iostream>
#include <vector>
#include <tuple>

struct employee {
    unsigned id;
    std::string name;
    std::string role;
    unsigned salary;
};

int main() {
    std::vector<employee> employees{
            {
                    1, "tom",   "cat",   10000
            },
            {
                    2, "jerry", "mouse", 10000
            }
    };

    for (const auto &[id, name, role, salary] : employees) {
        std::cout << "Name: " << name
                  << "Role: " << role
                  << "Salary: " << salary << '\n';
    }

    std::tuple<int, float, long> tup(1, 2.0, 4);
    // error
//    auto[a, b] = tup;
    auto[a, b, c] = tup;
    std::cout << "a:" << a << " ,b:" << b << " ,c:" << c << '\n';

    // C++ 17 之前做法，需要提前声明变量
    long d;
    std::tie(std::ignore, std::ignore, d) = tup;
    std::cout << "d:" << d << '\n';

    return 0;
}




