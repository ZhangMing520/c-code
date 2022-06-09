#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

int main()
{
    int x = 5;

    int *p = &x;
    cout << "x=" << x << endl;

    *p = 6;
    cout << "x=" << x << endl;
    return 0;
}

/**
 * @brief 分数转化为字母
 *
 * @param grade
 * @return string
 */
string letter_grade(double grade)
{
    static const double numbers[] = {
        97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0};

    static const char *const letters[] = {
        "A+", "A-", "A", "B+", "B-", "B", "C+", "C-", "C", "D", "F"};

    // 计算数组大小
    static const size_t hgrades = sizeof(numbers) / sizeof(*numbers);
    for (size_t i = 0; i < hgrades; i++)
    {
        if (grade > numbers[i])
            return letters[i];
    }
    
    return "?\?\?";
}