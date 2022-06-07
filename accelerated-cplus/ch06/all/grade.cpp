#include "grade.h"
#include "Student_info.h"
#include "median.h"
#include <stdexcept>
#include <numeric>

using std::domain_error;
using std::vector;

/**
 * @brief 根据学生的期中考试、期末考试以及家庭作业成绩来计算总成绩
 *
 * @param midterm
 * @param finals
 * @param homework
 * @return double
 */
double grade(double midterm, double finals, double homework)
{
    return 0.2 * midterm + 0.4 * finals + 0.4 * homework;
}

/**
 * @brief 获取学生成绩
 *
 * @param midterm
 * @param finals
 * @param hw        const vector<double> & 对参数类型为double的向量常量的引用
 * @return double
 */
double grade(double midterm, double finals, const vector<double> &hw)
{
    if (hw.size() == 0)
        throw domain_error("student has done no homework ");

    return grade(midterm, finals, median(hw));
}

/**
 * @brief
 *
 * @param s         Student_info
 * @return double
 */
double grade(const Student_info &s)
{
    return grade(s.midterm, s.finals, s.homework);
}

/**
 * @brief ch06函数，增加了家庭作业成绩是0的错误处理
 *
 * @param s
 * @return double
 */
double grade_aux(const Student_info &s)
{
    try
    {
        return grade(s);
    }
    catch (domain_error)
    {
        return grade(s.midterm, s.finals, 0);
    }
}

/**
 * @brief 求平均值
 *
 * @param v
 * @return double
 */
double average(const vector<double> &v)
{
    return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

/**
 * @brief 对家庭作业求平均值，然后求学生成绩
 *
 * @param s
 * @return double
 */
double average_grade(const Student_info &s)
{
    return grade(s.midterm, s.finals, average(s.homework));
}

/**
 * @brief 成绩小于60分，未及格
 *
 * @param s
 * @return true
 * @return false
 */
bool fgrade(const Student_info &s)
{
    return grade(s) < 60;
}

/**
 * @brief 成绩大于60分，及格
 *
 * @param s
 * @return true
 * @return false
 */
bool pgrade(const Student_info &s)
{
    return !fgrade(s);
}