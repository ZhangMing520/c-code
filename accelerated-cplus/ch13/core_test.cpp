/**
 * @file core_test.cpp
 * @author your name (you@domain.com)
 * @brief   指针版本
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
    vector<Core *> students;
    Core *record;
    char ch;
    string::size_type maxlen = 0;
    while (cin >> ch)
    {
        if (ch == 'U')
            record = new Core;
        else
            record = new Grad;
        record->read(cin);
        maxlen = max(maxlen, record->name().size());
        students.push_back(record);
    }

    sort(students.begin(), students.end(), compare_core_ptrs);

    for (vector<Core>::size_type i = 0; i != students.size(); i++)
    {
        cout << setw(maxlen + 1) << students[i]->name();
        try
        {
            double final_grade = students[i]->grade();
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec) << endl;
        }
        catch (domain_error e)
        {
            cout << e.what() << endl;
        }
        // 释放在读文件的时候生成的临时变量
        delete students[i];
    }
}