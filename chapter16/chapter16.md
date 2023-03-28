## chapter16 模板与范型编程



 当调用一个函数模板时，编译器通常会根据函数实参为我们推断模板实参

如	`cout << compare(1, 0) << endl;`	编译器会推断出模板参数为int

除了定义类型参数，还可以在模板中定义非类型参数，一个非类型参数表示一个值而非一个类型

```cpp
template<unsigned N, unsigned M>
int compare(const char (&p1)[N], const char (&p2)[M]){
    return strcmp(p1, p2);
}
compare("hi", "mom");
//实例化为	int cmpare(const char (&p1)[3], const char (&p2)[4]);
```

一个非类型参数可以是整型，或一个指针、引用（静态生命周期）

在模板定义内，模板非类型参数是常量

```cpp
template<typename T>
int compare(const T&, const T&){
    T v1, v2;
    if(v1 < v2)
        return -1;
    if(v2 < v1)
        return 1;
}
```

上面这样的设计体现出两个重要设计法则：

1. 我们使用引用，保证了函数可以用于不能拷贝的类型，如unique_ptr
2. 函数体中的条件判断仅使用了'<', 而未使用'>'   这减少了对类型T的要求

模板编译

为了生成一个实例化版本， 编译器需要掌握函数模板或类模板成员函数的定义。因此，模板的头文件一般既包括声明也包括定义