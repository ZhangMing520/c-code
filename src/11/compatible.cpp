//
// Created by zhangming on 2020/6/21.
//


// c98 c11 兼容

#include <iostream>

int main() {

#if __cplusplus >= 201103L
    std::cout << "c11" << std::endl;
#endif

#if    __cplusplus >= 199711L
    std::cout << "c98" << std::endl;
#endif
    
    return 0;
}