#include "analyze_homework.h"
#include <vector>
#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<Student_info> did, didnt;
    Student_info student;

    // while (read(cin, student))
    // {
    //     if (did_all_hw(student))
    //         did.push_back(student);
    //     else
    //         didnt.push_back(student);
    // }
    student.name = "ming";
    student.midterm = 90;
    student.finals = 90;
    student.homework = {80, 80};

    // 两个集合都不能为空，否则报错
    did.push_back(student);
    didnt.push_back(student);

    // if (did.empty())
    // {
    //     cout << "No student did all the homework!" << endl;
    //     return 1;
    // }
    // if (didnt.empty())
    // {
    //     cout << "Every student did all the homework!" << endl;
    //     return 1;
    // }

    write_analysis(cout, "median", median_analysis, did, didnt);
    write_analysis(cout, "average", average_analysis, did, didnt);
    write_analysis(cout, "median of homework turned in", optimistic_median_analysis, did, didnt);

    return 0;
}