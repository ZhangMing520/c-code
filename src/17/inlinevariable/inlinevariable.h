//
// Created by zhangming on 2020/6/8.
//

#ifndef CSTL_INLINEVARIABLE_H
#define CSTL_INLINEVARIABLE_H

// 只有头文件的库中启用内联变量

//其目的就是给定一个静态成员，然后使用inline关键字对其进行修饰，使得其实例在全局范围内都能访问到

#include <iostream>

class process_monitor {
public:
    // 多个.cpp文件中包含这个头文件时，链接阶段会出错
    static const inline std::string standard_string{ "some static globally available string"};
};
// 当该单元被重复包含时，会产生符号重定义的问题
//process_monitor global_process_monitor;

inline process_monitor global_process_monitor;


#endif //CSTL_INLINEVARIABLE_H
