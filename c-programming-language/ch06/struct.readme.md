1. 规则

- 结构体成员或名称和普通变量（即非成员）可以采用相同的名字，不会产生冲突，因为通过上下文分析总可以对其进行区分
- 不同结构体中的成员可以采用相同的名字
- 结构体声明之后没有定义变量表，则不需要为之分配存储单元，它仅仅描述了一个结构模板
```C
// x,y,z 就是变量列表
struct point{
    int x ; 
    int y;
} x,y,z ; 
```

2. 结构体的合法操作
- 拷贝（包含对函数传递参数）
- 作为一个单元对其赋值（包含从函数返回值）
- 通过&取其地址
- 访问结构体成员

3. 复杂表达式
```C
// 增加的是len的值而不是p的值   -> 优先级比 ++ 高
++p->len
// 等价于
++(p->len)

// 取的是str指向的值
*p->str
// 取str指向的值，再将str加1
*p->str++
// 等价于
(*p->str)++

// 先取str指向的值，再将p加1
*p++->str

```