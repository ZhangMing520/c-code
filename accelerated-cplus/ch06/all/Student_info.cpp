#include "Student_info.h"
#include "grade.h"
#include <algorithm>

using std::back_inserter;
using std::istream;
using std::vector;

/**
 * @brief   sort 第三个参数，是一个谓词。谓词是一个函数，会产生一个真值
 *
 * @param x
 * @param y
 * @return true
 * @return false
 */
bool compare(const Student_info &x, const Student_info &y)
{
    return x.name < y.name;
}

/**
 * @brief   读取
 *
 * @param in
 * @param hw        改变参数的值
 * @return istream&
 */
istream &read_hw(istream &in, vector<double> &hw)
{
    if (in)
    {
        // 清楚原先内容
        hw.clear();

        double x;
        while (in >> x)
        {
            hw.push_back(x);
        }

        // 清除流内部的错误状态，后续输入动作可以继续
        in.clear();
    }
    return in;
}

istream &read(istream &is, Student_info &s)
{
    is >> s.name >> s.midterm >> s.finals;

    read_hw(is, s.homework);
    return is;
}

/**
 * @brief
 *
 * @param students
 * @return vector<Student_info>
 */
// vector<Student_info> extract_fails(vector<Student_info> &students)
// {
//     vector<Student_info> fail;
//     // 复制不符合的结果到 fail
//     remove_copy_if(students.begin(), students.end(), back_inserter(fail), pgrade);
//     // remove_if 返回不符合元素的最后位置
//     students.erase(remove_if(students.begin(), students.end(), pgrade), students.end());

//     return fail;
// }

vector<Student_info> extract_fails(vector<Student_info> &students)
{
    vector<Student_info>::iterator iter = stable_partition(students.begin(), students.end(), pgrade);
    vector<Student_info> fail(iter, students.end());

    students.erase(iter, students.end());
    return fail;
}
