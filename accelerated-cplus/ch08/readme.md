1. 模板函数

> 类型参数 T 表示类型

> 当我们调用这个 median 函数的时候，系统环境会在编译期间把它判定的一个类型赋给 T。
> 例如，我们可以调用 median(vi) 从而给 median 函数一个 vector\<int> 类型的名为 vi 的对象。根据这个调用，系统环境就能推断出 T 是 int。

> 实际上，系统环境会对我们的代码进行实例化，就好像我们编写了一个参数类型为 vector\<int>、返回类型为 int 的特殊版本的 median 函数一样。

```cpp
// template <class T> 模板头
template <class T>
T median(vector<T> v)
{
    /* code */ 
}
```

2. typename

> 它会告知系统环境，vector<T>::size_type 是一个类型名 -- 即使系统环境还不知道类型 T 具体是代表什么的

```cpp
typedef typename vector<T>::size_type vec_sz;
```

3. 系统环境如何处理模板的实例化的

> 所有的系统环境都会以它自己的特定的方式去处理实例化
> 只有模板被实例化了，系统环境才能证实，模板代码能被用于指定的类型。

- 对于那些沿用了传统的编辑-编译-连接模式的系统环境来说，实例化动作经常不是在编译期间而是在连接期间发生的。因此，在连接期间，我们就可以发现那些看起来在编译期间可能发生的错误

- 为了对一个模板进行实例化，当前的大多数系统环境都要求这个模板的定义（而不仅仅是声明）必须是系统环境可以访问的。许多系统环境都要求模板的头文件直接地或者通过 #include 指令而把源文件包含进去 


4. 输入和输出流的迭代器

> 用于 istream 的迭代器满足了输入迭代器的要求，而用于 ostream 的则满足了输出迭代器的要求。
> ++将把迭代器推进到流的下一个值。对于输入流，*将产生在输入当前位置的值；而对于输出流，*将让我们写数据到相应的ostream 中。

```cpp
vector<int> v;

// 第二个参数创建了一个缺省（为空）的 istream_iterator<int>() 类型的迭代器，这个迭代器不会与任何的文件连接在一起。
// istream_iterator 类型有一个缺省值，而这个缺省值有一个性质，就是 istream_iterator 类型的迭代器一旦到达了文件末尾或者是处于错误中，那它就会和这个缺省值相等。
// 因此，能够使用这个缺省值来为 copy 表示那个“超过末尾元素一个单位的位置”的协定
copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));


// 输出 v 的元素，元素之间使用一个空格隔开
copy(v.begin(), v.end(), ostream_iterator<int>(cout," "));
```

5. 类型不全部出现在参数列表中

> 模板函数，如果类型不全部出现在参数列表中，那么调用程序就必须用具体的类型来限定 function-name （函数名）

```cpp
// 参数类型是用来为返回类型命名的
template <class T> T zero() { return 0; }

// 明确地提供返回类型
double x = zero<double>();

// 如果在声明中使用了模板类型参数定义的类型，就必须用关键字 typename 来限定这个声明
typename T::size_type name;
```
