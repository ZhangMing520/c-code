#include "core.h"
#include <algorithm>

using std::domain_error;
using std::istream;
using std::min;
using std::string;
using std::vector;

string Core::name() const { return n; }

double Core::grade() const
{
    return ::grade(midterm, finals, homework);
}

istream &Core::read_common(istream &in)
{
    in >> n >> midterm >> finals;
    return in;
}

istream &Core::read(istream &in)
{
    read_common(in);
    read_hw(in, homework);
    return in;
}

/////////////////////////////////// Grad

istream &Grad::read(istream &in)
{
    read_common(in);
    in >> thesis;
    read_hw(in, homework);
    return in;
}

/**
 * @brief 选择论文成绩与家庭作业成绩低一点的那个成绩
 *
 * @return double
 */
double Grad::grade() const
{
    return min(Core::grade(), thesis);
}

/////////////////////////////// Student_info

istream &Student_info::read(istream &is)
{
    char ch;
    is >> ch;
    if (ch == 'U')
        cp = new Core(is);
    else
        cp = new Grad(is);

    return is;
}


/////////////////////////////////////////////////////////////

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

bool compare(const Core &c1, const Core &c2)
{
    return c1.name() < c2.name();
}

bool compare_core_ptrs(const Core *cp1, const Core *cp2)
{
    return compare(*cp1, *cp2);
}