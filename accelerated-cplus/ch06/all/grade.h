#ifndef GUARD_grade_h
#define GUARD_grade_h

#include "Student_info.h"
#include <vector>

double grade(double, double, double);
double grade(const Student_info &);
double grade(double, double, const std::vector<double> &);

// ch06 add
double grade_aux(const Student_info &);

double average(const std::vector<double> &);
double average_grade(const Student_info &);

bool fgrade(const Student_info &);
bool pgrade(const Student_info &);

#endif