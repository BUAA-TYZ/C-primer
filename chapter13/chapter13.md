## 拷贝控制



#### 拷贝构造函数

一个构造函数的第一个参数是自身类类型的引用，且任何额外参数都有默认值，其参数几乎总是const的

```cpp
class Foo{
public:
    Foo();
    Foo(const Foo&);
};
```

拷贝构造函数不应是explicit的，因为往往拷贝构造函数会隐式进行

合成拷贝构造函数：编译器将其参数的成员逐个拷贝到正在创建的对象中

> 对类类型成员会使用其拷贝构造函数，内置成员则直接拷贝（数组也可以！虽然数组不可直接拷贝但其会逐元素的进行拷贝）

**拷贝初始化**

```cpp
string dots(10, '.');
string s(dots);
string s2 = dots;
string null_book = "99-9999";
string nines = string(10, '9');
```

直接初始化：编译器使用普通的函数匹配选择最适合的构造函数

拷贝初始化：将右侧对象拷贝到正在创建对象中，若需要还要类型转换==（拷贝构造函数或移动构造函数）==

以下情况会出现拷贝初始化：

- 用=定义变量（可能）
- 将一个对象作为实参传递给一个非引用的形参
- 从一个返回类型非引用的函数返回一个对象
- 用花括号列表初始化一个数组或一个聚合类

#### 拷贝赋值运算符

```cpp
class Foo{
public:
    Foo();
    Foo& operator=(const Foo&);
};
```

合成拷贝赋值运算符与拷贝构造函数相似，最后会返回一个左侧运算对象的引用 `*this`



- 需要析构函数的类几乎总需要拷贝、赋值操作
- 需要拷贝的类也需要赋值，反之亦然

将拷贝控制操作定义为删除的

```cpp
class Nocopy{
	Nocopy() = default;
    Nocopy(const Nocopy&) = delete;				//阻止拷贝
    Nocopy& operator=(const Nocopy&) = delete;	//阻止赋值
};
```

$p_{452}$	合成的拷贝控制成员可能会被编译器定义成删除的



一个负责资源管理的类，行为可能像值，也可能像指针，并且可能需要一个自己的swap操作

当编写swap操作时：
```cpp
//错误
void swap(Foo& lhs, Foo& rhs){
	std::swap(lhs.h, rhs.h);
}
//正确，原因在于class可能定义了专门的swap来swap类成员，第一种则必然使用std版本
void swap(Foo& lhs, Foo& rhs){
    using std::swap;
	swap(lhs.h, rhs.h);
}

//“拷贝并交换”处理赋值天然正确且能处理自赋值
Hasptr& Hasptr::operator=(Hasptr rhs){
	swap(*this, rhs);
    return *this;
}
```



#### 对象移动

`int &&r = 42;`

返回非引用的函数，算术、关系、位以及后置递增/递减运算符都生成右值，我们不能将一个左值引用绑定其上，但可以将一个const的左值引用或右值引用绑定

==左值持久，右值短暂==	故一切变量皆左值，包括右值引用

右值要么是**字面常量**，要么是表达式求值过程中**创建的临时对象**。我们得知：

- 所引用的对象将要被销毁
- 该对象没有其他用户

右值引用可以自由地接管所引用的对象的资源

使用**move**函数显示将一个左值转换成对应右值引用

```cpp
#include<utility>
int &&rr1 = 42;
int &&r3 = std::move(rr1);
```

调用move就意味着承诺除了对rr1赋值或销毁，我们不再使用它

**移动构造函数**

确保移后源对象被销毁是无害的, 如下对s进行析构函数释放资源也是安全的

```cpp
Strvec::Strvec(Strvec &&s) noexcept:
elements(s.elements), first_free(s.first_free){
	s.elements = s.first_free = nullptr;
}
```

$p_{474}$ 为什么我们需要noexcept

- ==移动操作之后，移后源对象必须保持有效（意味着可以进行正常的操作）、可析构的状态，但用户不能对其值有任何假设==

- 当一个类没有定义自己的拷贝控制成员且它的所有成员都能移动构造或赋值时，编译器才会为它合成移动构造函数或移动赋值算符
- 定义移动操作的类必须也定义拷贝操作，否则这些成员默认被定义为删除的



如果没有定义移动操作，右值也被拷贝	如：`Foo x;Foo z(std::move(x));`	

Foo&&将被转换为const Foo&从而调用拷贝构造函数

赋值运算符既是移动赋值，也是拷贝赋值	如：

```cpp
Foo& operator=(Foo rhs){
	swap(*this, rhs);
    return *this;
}			//这里形参使用了拷贝初始化，依据实参类型可能是两种赋值
```



 成员函数也可以提供两个版本：拷贝及移动版本—一个版本接受const的左值引用，一个版本接受非const右值引用	如：

```cpp
void push_back(const X&);	//可以绑定到任意类型的X
void push_back(X&&);		//只能绑定到右值
```

$p_{483}$	引用限定符		[一个专门用于解释的Foo类](./Foo.cpp)
