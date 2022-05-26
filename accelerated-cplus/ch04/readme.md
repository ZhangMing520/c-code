1. 引用

> 对 hw 所做的任何动作都等价于对 homework 做同样的动作
> 一个引用的引用跟定义原来对象的引用的效果是一样的

```cpp
vector<double> homework;
// hw 是 homework 的有一个替代名
vector<double>& hw = homework;

// chw 是 homework 的一个只读的替代名
// const 确保了我们将不会对 chw 做任何可能改变它的值的动作
const vector<double>& chw = homework;

// hw1 是 homework 的有一个替代名
vector<double>& hw1 = hw;

// 错误，请求了对 chw 的写访问
// const 不允许
vector<double>& hw2 = chw;
```

2. 非常量引用参数对应的参数必须是左值 -- 必须是非临时对象

> 按值传递或与一个常量引用连接在一起的参数可以取任何值

```cpp
vector<double> emptyvec()
{
    vector<double> v ; 
    return v;
}

// istream &read_hw(istream &in, vector<double> &hw)
// 错误：emptyvec() 不是左值，调用 emptyvec 时所创建的那个未命名的向量将会在 read_hw 返回时立即消失
read_hw(cin, emptyvec())
```