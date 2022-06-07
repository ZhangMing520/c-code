#ifndef GURAD_Student_info_h
#define GURAD_Student_info_h

#include <string>
#include <vector>
#include <iostream>

struct Student_info
{
    std::string name;
    double midterm, finals;
    std::vector<double> homework;

    // 新增的
    std::istream &read(std::istream &);
    // 常量成员函数
    double grade() const;
};

#endif