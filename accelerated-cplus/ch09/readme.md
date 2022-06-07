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