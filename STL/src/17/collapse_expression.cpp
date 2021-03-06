//
// Created by zhangming on 2020/6/8.
//

// 使用折叠表达式实现辅助函数

// 只是简单的对参数集进行简单的递归，然后应用二元操作符 + 将每个参数加在一起

//C++17中的折叠参数包支持如下二元操作符：
//+ - * / % ^ & | = < > << >> += -= *= /= %= ^= &= |= <<= >>= == != <= >= && || , .* ->*

//当...在操作符右侧时，称为有“右折叠”；当...在操作符左侧时，称为”左折叠“
// 一元左折叠的扩展表达式为1+(2+(3+(4+5)))，一元右折叠的扩展表达式为(((1+2)+3)+4)+5

#include <iostream>

// 参数包ts
// 函数必须将参数包展开，然后使用表达式进行求和
template<typename ... Ts>
auto sum(Ts ... ts) {
    // ts 没有传入参数会导致错误
//    return (ts + ... );

   //  具有初始值的折叠表达式称为二元折叠
    return (ts + ... + 0 );
}


int main() {
    int the_sum(sum(1, 2, 3));

    std::cout << the_sum << '\n';

//    std::string a("Hello ");
//    std::string b{"World"};
//
//    std::cout << sum(a, b) << '\n';

    return 0;
}
