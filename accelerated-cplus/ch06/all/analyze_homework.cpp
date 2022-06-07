/**
 * @file analyze_homework.cpp
 * @author your name (you@domain.com)
 * @brief 对家庭作业成绩采用不同方式分析，展示不同分析方法结果
 * @version 0.1
 * @date 2022-06-03
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "analyze_homework.h"
#include "grade.h"
#include "median.h"
#include <algorithm>
#include <numeric>

using std::back_inserter;
using std::endl;
using std::vector;

/**
 * @brief 检查一个学生是否做了所有的家庭作业
 *
 * @param s
 * @return true 做了所有的家庭作业
 * @return false
 */
bool did_all_hw(const Student_info &s)
{
    // 所有值中是否有为0的，一个为0的成绩意味着这个作业并没有提交。
    return (find(s.homework.begin(), s.homework.end(), 0) == s.homework.end());
}

/**
 * @brief 对每个学生家庭作业采用中位数分析，然后对所有成绩采用中位数分析
 *
 * @param students
 * @return double
 */
double median_analysis(const std::vector<Student_info> &students)
{
    vector<double> grades;

    transform(students.begin(), students.end(), back_inserter(grades), grade_aux);

    return median(grades);
}

/**
 * @brief 对每个学生家庭作业采用平局值分析，然后对所有成绩采用中位数分析
 *
 * @param students
 * @return double
 */
double average_analysis(const std::vector<Student_info> &students)
{
    vector<double> grades;

    transform(students.begin(), students.end(), back_inserter(grades), average_grade);

    return median(grades);
}

/**
 * @brief 假设学生上交的家庭作业的数量对他们的家庭作业成绩并没有影响
 *
 * @param s
 * @return double
 */
double optimistic_median(const Student_info &s)
{
    vector<double> nonzero;
    // 取出非0元素
    remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);
    if (nonzero.empty())
    {
        return grade(s.midterm, s.finals, 0);
    }
    else
    {
        return grade(s.midterm, s.finals, median(nonzero));
    }
}

/**
 * @brief
 *
 * @param students
 * @return double
 */
double optimistic_median_analysis(const std::vector<Student_info> &students)
{
    vector<double> grades;

    transform(students.begin(), students.end(), back_inserter(grades), optimistic_median);

    return median(grades);
}

/**
 * @brief
 *
 * @param out
 * @param name
 * @param analysis
 * @param did
 * @param didnt
 */
void write_analysis(std::ostream &out, const std::string &name,
                    double analysis(const vector<Student_info> &students),
                    const vector<Student_info> &did, const vector<Student_info> &didnt)
{
    out << name << endl;
    out << "did grade: " << analysis(did) << "\t didnt grade: " << analysis(didnt) << endl;
}