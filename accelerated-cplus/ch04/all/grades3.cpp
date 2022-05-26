/**
 * @file grades3.cpp
 * @author your name (you@domain.com)
 * @brief   g++ *.cpp -o grades3
 *         tomcat 100 90 93 99 90 jetty 100 90 93 99 90 d d
 *           jetty  93.2
 *          tomcat  93.2
 *
 * @version 0.1
 * @date 2022-05-26
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iomanip>
#include <algorithm>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "Student_info.h"
#include "grade.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::max;
using std::setprecision;
using std::setw;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    while (read(cin, record))
    {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    sort(students.begin(), students.end(), compare);

    for (vector<Student_info>::size_type i = 0; i < students.size(); i++)
    {
        // 添加空格填充姓名达到 maxlen+1
        // 修改是短暂的。每个标准输出运算符在完成了它的输出动作之后就马上重置流的宽度
        cout << setw(maxlen + 1) << students[i].name << "  ";
        try
        {
            double final_grade = grade(students[i]);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec);
        }
        catch (domain_error e)
        {
            cout << e.what();
        }
        cout << endl;
    }

    return 0;
}
