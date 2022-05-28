#include "Student_info.h"
#include "grade.h"
#include <list>
#include <cctype>

using std::list;
using std::string;
using std::vector;

/**
 * @brief       判断学生是否及格
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
 * @brief v1.0 获取通过考试和未通过考试的学生
 *
 * @param students
 * @return vector<Student_info>
 */
// vector<Student_info> extract_fails(vector<Student_info> &students)
// {
//     vector<Student_info> fail, pass;

//     for (vector<Student_info>::size_type i = 0; i < students.size(); ++i)
//     {
//         if (fgrade(students[i]))
//         {
//             fail.push_back(students[i]);
//         }
//         else
//             pass.push_back(students[i]);
//     }
//     students = pass;
//     return fail;
// }

/**
 * @brief v2.0 删除元素，不需要重新声明一个 vector<Student_info> pass
 *
 * @param students
 * @return vector<Student_info>
 */
// vector<Student_info> extract_fails(vector<Student_info> &students)
// {
//     vector<Student_info> fail;
//     vector<Student_info>::size_type i = 0;

//     // size是变化的，需要每一次获取
//     while (i < students.size())
//     {
//         if (fgrade(students[i]))
//         {
//             fail.push_back(students[i]);
//             // 删除索引为i的元素，让i指示序列中的下一个元素
//             students.erase(students.begin() + i);
//         }
//         else
//             i++;
//     }
//     return fail;
// }

/**
 * @brief v3.0 使用迭代器替代索引
 *
 * @param students
 * @return vector<Student_info>
 */
// vector<Student_info> extract_fails(vector<Student_info> &students)
// {
//     vector<Student_info> fail;
//     vector<Student_info>::iterator iter = students.begin();

//     // erase 使迭代器失败，必要在每一次的循环过程中调用 students.end()
//     while (iter != students.end())
//     {
//         if (fgrade(*iter))
//         {
//             fail.push_back(*iter);
//             // 调用 erase 来删除向量中的一个元素，那么所有指向位于被删除元素后面的元素的迭代器都会失效
//             // 需要把 erase 的返回值赋给 iter
//             iter = students.erase(iter);
//         }
//         else
//             ++iter;
//     }
//     return fail;
// }

/**
 * @brief v4.0 用 list 替代 vector，中间增加删除性能提升
 *
 * @param students
 * @return list<Student_info>
 */
list<Student_info> extract_fails(list<Student_info> &students)
{
    list<Student_info> fail;
    list<Student_info>::iterator iter = students.begin();

    while (iter != students.end())
    {
        if (fgrade(*iter))
        {
            fail.push_back(*iter);
            iter = students.erase(iter);
        }
        else
            ++iter;
    }
    return fail;
}
