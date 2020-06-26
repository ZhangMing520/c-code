//
// Created by zhangming on 2020/6/7.
//

//构造函数自动推导模板的类型


#include <iostream>


template<typename T1, typename T2, typename T3>
class my_wrapper {
private:
    T1 t1;
    T2 t2;
    T3 t3;

public :
    explicit my_wrapper(T1 t1_, T2 t2_, T3 t3_) : t1{t1_}, t2{t2_}, t3{t3_} {}

};


template<typename T>
struct sum {
    T value;

    // 构造函数
    template<typename ... Ts>
    sum(Ts &&... values) : value{(values + ...)} {}
};

// 指导性显式推导
// 下面的是构造函数
// T 类型就是 std::common_type_t<Ts...>
template<typename ... Ts>
sum(Ts &&... values) -> sum<std::common_type_t<Ts... >>;


int main() {

    // C++ 17 之前写法
    // my_wrapper<int, double, char *> wrapper{1, 2.0, "abc"};

    my_wrapper wrapper{1, 2.0, "abc"};

    sum s{1u, 2.0, 3, 4.0f};
    sum string_sum{std::string{"abc"}, "def"};
    std::cout << s.value << '\n'
              << string_sum.value << '\n';
}