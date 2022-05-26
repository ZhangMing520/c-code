/**
 * @file grades2.cpp
 * @author your name (you@domain.com)
 * @brief   组织程序和数据
 * @version 0.1
 * @date 2022-05-26
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

double grade(double midterm, double finals, double homework);

double grade(double midterm, double finals, const vector<double> &hw);

double median(vector<double> vec);

istream &read_hw(istream &in, vector<double> &hw);

int main()
{
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " + name + "!" << endl;

    cout << "Please enter your midterm and final exam grades: ";
    double midterm, finals;
    cin >> midterm >> finals;

    cout << "Enter all your homeword grades, "
            "followed by end-of-file: ";

    vector<double> homework;
    read_hw(cin, homework);
    double midian = median(homework);

    try
    {
        double final_grade = grade(midterm, finals, midian);
        streamsize prec = cout.precision();
        cout << "Your final grade is " << setprecision(3)
             << final_grade << setprecision(prec) << endl;
    }
    catch (domain_error)
    {
        cout << endl
             << "You must enter your grades. "
             << "Please try again." << endl;
        return 1;
    }

    return 0;
}

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
 * @brief 计算一个 vector<double> 类型的变量的中值
 *
 * @param vec   整个 vector 参数都会被复制
 * @return double
 */
double median(vector<double> vec)
{
    typedef vector<double>::size_type vec_sz;

    vec_sz size = vec.size();
    if (size == 0)
        throw domain_error("median of an empty vector");

    sort(vec.begin(), vec.end());
    vec_sz mid = size / 2;

    return size % 2 == 0 ? (vec[mid] + vec[mid + 1]) / 2 : vec[mid];
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