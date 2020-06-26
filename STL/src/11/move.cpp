//
// Created by zhangming on 2020/6/21.
//

// 避免非必要拷贝和临时对象
// "被传入的值（也就是x+x的和以及x）不再被调用者使用"，如此一来无需为它建立一份copy且“以某种方式move其内容进入新建元素中”

// move 将其实参转成一个所谓的 rvalue reference，一种被声明为 X&& 的类型。
// rvalue 不具名的临时对象只能出现于复制操作的右侧，可被改动内容，不在被需要的（临时）对象，所以你可以“偷”器内容或者资源

// 为什么需要拷贝和临时对象？
// 集合（collection）提供 value semantic 以及安插“临时对象” 或者“安插后会被使用或被改动的对象”的能力

#include <iostream>
#include <set>
#include <utility>

template<typename X>
void createAndInsert(std::set<X> &coll);

class X {
public:
    // copy constructor
    X(const X &lvalue);

// move constructor
// 将一个既有元素的内容搬迁（move）到新元素中
// 另外，你必须确保对于被传对象（其value被偷取）的任何改动都不至于冲击新对象（如今拥有value）状态，
// 因此往往必须清楚被传入的实参的内容，将 nullptr 赋值给“指向了容器元素”的成员函数
// string的 move构造函数只是将既有的内部字符数组赋予新对象，而非建立一个新array然后复制所有元素

    X(const X &&rvalue);

    // copy assignment operator
    X&operator=(const X& lvalue);
    // move assignment operator
    X&operator=( X&& lvalue);
};

int main() {

    return 0;
}

template<typename X>
void createAndInsert(std::set<X> &coll) {
    X x;
    coll.insert(x);  // insert copy of x
    // c11 moves contents of temporary value
    coll.insert(x + x);  // insert copy of template value
    coll.insert(x);  // insert copy of x ,although x is not used any longer

    coll.insert(std::move(x));  // move contents of x
}


