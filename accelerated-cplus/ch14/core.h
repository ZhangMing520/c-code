#ifndef GUARD_core_h
#define GUARD_core_h

#include <istream>
#include <string>
#include <vector>

class Core
{
    friend class Student_info;

public:
    Core() : midterm(0), finals(0) {}
    Core(std::istream &is) { read(is); };

    virtual ~Core() {}

    std::string name() const;
    virtual std::istream &read(std::istream &);
    virtual double grade() const;

protected:
    std::istream &read_common(std::istream &);
    double midterm, finals;
    std::vector<double> homework;

    virtual Core *clone() const { return new Core(*this); }

private:
    std::string n;
};

/**
 * @brief 研究生要求
 *
 */
class Grad : public Core
{
public:
    // 隐式地调用 Core::Core() 函数来初始化对象中的基类部分
    Grad() : thesis(){};
    Grad(std::istream &is) { read(is); };
    double grade() const;
    std::istream &read(std::istream &);

protected:
    Grad *clone() const { return new Grad(*this); }

private:
    double thesis;
};

/**
 * @brief 句柄类
 *
 */
class Student_info
{
public:
    Student_info() : cp(0){};
    Student_info(std::istream &is) : cp(0) { read(is); };

    std::istream &read(std::istream &);

    std::string name() const
    {
        if (cp)
            return cp->name();
        else
            throw std::runtime_error("unintialized Student");
    }

    double grade() const
    {
        if (cp)
            return cp->grade();
        else
            throw std::runtime_error("unintialized Student");
    }

    static bool compare(const Student_info &s1, const Student_info &s2)
    {
        return s1.name() < s2.name();
    }

private:
    Handle<Core> cp;
};

double grade(double midterm, double finals, double homework);
double grade(double midterm, double finals, const std::vector<double> &hw);
double median(std::vector<double>);
std::istream &read_hw(std::istream &in, std::vector<double> &hw);

bool compare(const Core &, const Core &);
bool compare_core_ptrs(const Core *, const Core *);
#endif