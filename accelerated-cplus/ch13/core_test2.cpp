/**
 * @file core_test2.cpp
 * @author your name (you@domain.com)
 * @brief   句柄版本
 * @version 0.1
 * @date 2022-06-19
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "core.h"
#include <iostream>
#include <algorithm>
#include <iomanip>

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::max;
using std::setprecision;
using std::setw;
using std::streamsize;
using std::string;
using std::vector;

int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;
    while (record.read(cin))
    {
        maxlen = max(maxlen, record.name().size());
        students.push_back(record);
    }

    sort(students.begin(), students.end(), Student_info::compare);

    for (vector<Core>::size_type i = 0; i != students.size(); i++)
    {
        cout << setw(maxlen + 1) << students[i].name();
        try
        {
            double final_grade = students[i].grade();
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec) << endl;
        }
        catch (domain_error e)
        {
            cout << e.what() << endl;
        }
    }
}