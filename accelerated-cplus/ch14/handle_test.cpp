#include <string>
#include <iostream>
#include "handle.h"
#include "core.h"
#include <vector>
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
    vector<Handle<Core>> students;
    Handle<Core> record;
    char ch;
    string::size_type maxlen = 0;

    while (cin >> ch)
    {
        // 1. Handle<T>(T*) 构造 Handle<Core> 的对象。
        // 2. 调用 Handle<T>::operator 来将 Handle<Core> 赋值给左边的对象
        if (ch == 'U')
            record = new Core;
        else
            record = new Grad;
        record->read(cin);
        maxlen = max(maxlen, record->name().size());
        students.push_back(record);
    }

    sort(students.begin(), students.end(), compare_core_handles<Core>);
    for (vector<Handle<Core>>::size_type i = 0; i != students.size(); i++)
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
    }
    return 0;
}