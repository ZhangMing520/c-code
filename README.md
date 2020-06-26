1. 相关网址

[C++17 STL Cook Book](https://chenxiaowei.gitbook.io/c-17-stl-cook-book/chapter1-0-chinese/chapter1-1-chinese)
[C++17 STL Cook Book 作者博客地址](https://arne-mertz.de/)

2. 将变量作用域限制在if和switch区域内
```c++
//首先，创建一个std::lock_guard。这个类接收一个互斥量和作为其构造函数的参数。
//这个类在其构造函数中对互斥量上锁，之后当代码运行完这段区域后，其会在析构函数中对互斥量进行解锁。
//这种方式避免了忘记解锁互斥量而导致的错误。C++17之前，为了确定解锁的范围，需要一对额外的括号对

if (std::lock_guard<std::mutex> lg {my_mutex}; some_condition) {
  // Do something
}

```

3. 头文件中 inline 作用
> 为了能提供全局可以使用的方法，通常会在头文件中定义函数，这可以让C++的所有模块都调用头文件中函数的实现
>(C++中，头文件中实现的函数，编译器会隐式的使用inline来进行修饰，从而避免符号重复定义的问题)。
>这样就可以将函数的定义单独的放入模块中。之后，就可以安全的将这些模块文件链接在一起了。
>这种方式也被称为定义与单一定义规则(ODR，One Definition Rule)

> 使用inline声明所有符号之后，连接器只会接受其找到的第一个符号，而将后续该符号的不同实现丢弃