1. 定义与声明
- 定义指变量建立或分配存储单元的位置
- 声明则指明变量性质的位置，但并不分配存储单元
- 外部变量和静态变量的缺省值为0。未经显式初始化的自动变量的值为未定义值（即为垃圾）

2. typedef定义新类型的步骤
- 在传统的变量声明表达式里，用新的类型名替换变量名，然后把关键字typedef加在该语句的开头就可以了

```C
// 传统变量声明表达式
int a;
// 使用新的类型名myint_t替换变量名a
int myint_t;
// 在语句开头加上typedef关键字，myint_t就是我们定义的新类型
typedef int myint_t;


// 传统变量声明表达式
void (*pfunA)(int a);
// 使用新的类型名PFUNA替换变量名pfunA
void (*PFUNA)(int a);
// 在语句开头加上typedef关键字，PFUNA就是我们定义的新类型
typedef void (*PFUNA)(int a);

```