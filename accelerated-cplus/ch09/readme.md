1. Student_info 成员函数

> 函数名的::是一个作用域运算符，这个函数是 Student_info 类型的一个成员

> Student_info& 参数将隐含在任何的调用中

- 函数名是 Student_info::read 而不是 read
- 因为这个函数是 Student_info 对象的一个成员，所以我们不需要把一个 Student_info 对象作为参数来传递，而且根本不需要定义一个 Student_info 对象
- 直接地范文对象的数据对象

```cpp
// .h
struct Student_info
{
    std::string name;
    double midterm, finals;
    std::vector<double> homework;

    // 新增的
    std::istream &read(std::istream &);
    double grade() const;
};

// .cpp
istream &Student_info::read(istream &in)
{
    in >> name >> midterm >> finals;
    read_hw(in, homework);
    return in;
}
```

2. ::grade 调用

> 把 :: 放在一个名称之前，那就表明了要使用这个名称的某一个版本，而使用的这个版本不能是任何事物的成员。

```cpp
::grade(midterm, finals, homework)
```

3. 常量成员函数

> 常量成员函数不可以改变正在由它们执行的对象的内部状态：如果对一个名叫 s 的 Student_info 对象调用了 s.grade() ，这样做将不会修改 s 的数据成员。

> 函数保证了不会修改对象的值，所以可以用常量对象调用它。出于同样的原因，不能对常量对象调用非常量函数。

> 即使一个程序从未直接创建过任何的常量对象，它还是有可能在函数调用的过程中创建许多对常量对象的引用。如果把一个非常量对象传递给一个具有常量引用参数的函数，那么这个函数就会把这个对象当做常量来处理，同时编译程序将允许它只调用这种对象的常量成员。

```cpp
double grade() const
```

4. class 和 struct 的唯一差别

> 如果在第一个保护标识符之前有成员，那么对于 struct 和 class 来说，应用于这些成员的缺省保护方式是彼此不同的。
> 如果我们使用 class Student_info，那么，在第一个{和第一个保护标识符之间的所有成员都是私有的。
> 相反，如果我们编写了 struct Student_info，那么在{和第一个保护标识符之间的所有成员都是公有的

> 一般而言，程序设计风格是保留结构以指示简单的类型，并且希望公开这些类型的数据结构。
> 既然我们想构造一个类型并控制对其成员的访问，那我们就应该使用类来定义类型。

```cpp
class Student_info {
public:
    double grade() const;
}
// 等价于
struct Student_info {
    double grade() const;
}

class Student_info {
    std::string name;
public:
    double grade() const;
}
// 等价于
struct Student_info {
private:
    std::string name;
public:
    double grade() const;
}
```

5. 构造函数

> 如果对象是一个局部变量，那么数据成员将会被缺省初始化
> 如果是下面的三种情况中之一，那么对象的成员会被数值初始化
   - 对象被用来初始化一个容器元素
   - 为映射表添加一个新元素，而对象是这个添加动作的副作用
   - 定义一个有特定长度的容器，对象是这个容器的元素 

> 实质：
   - 如果对象属于一种自定义类型，而这种自定义类型定义了一个或者多个构造函数，那么合适的构造函数就完全控制了对类的对象的初始化
   - 如果对象属于内部类型，那么数值初始化方式会把它设置为零，而缺省初始化方式会给它一个未定义的值
   - 否则，对象就只能是属于未定义任何构造函数的自定义类型。这样的话，对这个对象的数值或者缺省初始化操作就会对它的每一个数据成员进行相应的数值或缺省初始化。如果有任一数据成员属于一种本身具有构造函数的自定义类型的话，那这个初始化过程都将会是递归的

> Student_info 类属于第三种情况：它是一个自定义类型，但是并没有明确地说明 Student_info 对象的构造方式。因此，如果我们定义了一个局部的 Student_info 变量，那么 n 和 homework 就会分别被自动地初始化成空的字符串和向量，这是因为它们是具有构造函数的类对象。与之相反，对 midterm 和 finals 的缺省初始化将会给它们未定义的值。这就意味着它们将保存存储在它们被创建时所获得的内存区域中的任何无用信息。

> 应该确保所有的数据成员在任何时候都会具有有意义的值

6. 构造函数初始化程序

> 在 : 和 { 之间有一系列的构造函数初始化程序，它们命令编译程序初始化给定的成员，并且在初始化的时候使用出现在相应的括号之间的值

```cpp
// homework 成员称为一个空的向量，n 成员称为一个空字符串
// 而 midterm finals 成员则被初始化为零
Student_info::Student_info() : midterm(0), finals(0) {}

```

7. 创建一个新的类对象步骤

- 实现分配内存以保存这个对象
- 按照构造函数初始化程序列表对对象进行初始化
- 执行构造函数函数体