//
// Created by zhangming on 2020/6/21.
//

#include <vector>
#include <list>

int main() {

    // 在两个 template 表达式的闭符之间放一个空格的要求已经过时了
    // each version ok
    std::vector<std::list<int> > a;
    // since 11 ok
    std::vector<std::list<int>> b;

    return 0;
}

