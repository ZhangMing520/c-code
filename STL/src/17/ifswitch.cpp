//
// Created by zhangming on 2020/6/7.
//

//将变量作用域限制在if和switch区域内
// if 互斥锁

/*// if: since C++17
if (auto var (init_value); condition){
// branch A. var is accessible
} else {
// branch B. var is accessible
}
// var is not accessible any longer*/

/*// switch: since C++17
switch(auto var (init_value); var){
case 1: ...
case 2: ...
...
}
// var is not accessible any longer*/


#include <iostream>

int main() {

    if (auto a(3); a != 3) {
        std::cout << a << '\n';
    } else {
        std::cout << a << '\n';
    }
    // error
//    std::cout << a  ;

    switch (auto b('c');b) {
        case 'c':
            std::cout << "C\n";
    }
    // error
    // std::cout << b;

    return 0;
}

