#ifndef GURAD_Student_info_h
#define GURAD_Student_info_h

#include <string>
#include <vector>
#include <iostream>

// struct Student_info
// {
//     std::string name;
//     double midterm, finals;
//     std::vector<double> homework;

//     // 新增的
//     std::istream &read(std::istream &);
//     // 常量成员函数
//     double grade() const;
// };

class Student_info
{
public:
    Student_info();
    Student_info(std::istream &);

    std::string name() const { return n; }
    bool valid() const { return !homework.empty(); }

    double grade() const;
    std::istream &read(std::istream &);

private:
    std::string n;
    double midterm, finals;
    std::vector<double> homework;
};

bool compare(const Student_info &, const Student_info &);

#endif