//
// Created by zhangming on 2020/6/7.
//


// 使用 constexpr-if 简化编译

// constexpr-if的工作机制与传统的if-else类似
//不同点就在于前者在编译时进行判断，后者在运行时进行判断。所以，使用constexpr-if的代码在编译完成后，
//程序的这一部分其实就不会有分支存在

// 模板化过程中，通常要以不同的方式做某些事情，比如特化模板类型

#include <iostream>
#include <vector>

template<typename T>
class addable {
    T val;
public:
    addable(T v) : val(v) {}

    template<typename U>
    T add(U x) const {
        // T 是  std::vector 类型
        if constexpr (std::is_same<T, std::vector<U>>::value) {
            auto copy(val);
            for (auto &n : copy) {
                n += x;
            }
            return copy;
        } else {
            return val + x;
        }
    }

    //  C++ 17之前做法
    // std::enable_if_t<condition, type>，如果条件为真，那么就为type类型，反之std::enable_if_t表达式不会做任何事

//    template<typename U>
//    std::enable_if_t<!std::is_same<T, std::vector<U>>::value, T>
//    add(U x) const {
//        return val + x;
//    }
//
//    template<typename U>
//    std::enable_if_t<std::is_same<T, std::vector<U>>::value, std::vector<U>>
//    add(U x) const {
//        auto copy(val);
//        for (auto &n: copy) {
//            n += x;
//        }
//        return copy;
//    }
};

int main() {
    addable<int>{1}.add(2); // is 3
    addable<float> {1.f}.add(2.0); // is 3.0
    addable<std::string> {"aa"}.add("bb"); // is "aabb"

    std::vector<int> v{1, 2, 3};
    addable<std::vector<int>>{v}.add(10); // is std::vector<int> {11, 12, 13}

    std::vector<std::string> sv{"a", "b", "c"};
    addable<std::vector<std::string>>{sv}.add(std::string{"z"}); // is {"az", "bz", "cz"}

    return 0;
}