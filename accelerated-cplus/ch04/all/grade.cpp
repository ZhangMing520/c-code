#include "grade.h"
#include "Student_info.h"
#include "median.h"
#include <stdexcept>

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
 * @brief
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