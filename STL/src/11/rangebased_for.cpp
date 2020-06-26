//
// Created by zhangming on 2020/6/21.
//

// for  声明每个元素是 reference ，避免调用每个元素的copy构造函数和析构函数

// for 循环中不能有任何显示类型转换

#include <iostream>
#include <string>
#include <vector>

template<typename T>
void printElements(const T &coll);

class C {
public:
    C(const std::string &s) : c(s) {}
    //explicit C(const std::string &s) : c(s) {}

    // cout<<
    friend std::ostream &operator<<(std::ostream &, const C &);

private:
    std::string c;
};

std::ostream &operator<<(std::ostream &cout, const C &c) {
    cout << c.c;
    return cout;
}

int main() {

    for (int i : {2, 23, 4, 5, 5, 4, 6}) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::vector<std::string> vs{"aa", "bb"};
    // error  explicit C(const std::string &s) : c(s) {}
    for (const C &elem:vs) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    return 0;
}

template<typename T>
void printElements(const T &coll) {
    for (const auto &elem : coll) {
        std::cout << elem << std::endl;
    }
}
