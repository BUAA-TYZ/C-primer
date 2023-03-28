## 面向对象程序设计



OOP(objected-oriented programming) 核心思想：数据抽象、继承、动态绑定

从**基类**继承得到**派生类**

定义一个Quote类

一个派生类使用派生类列表指出基类

```cpp
class Quote{
public:
	std::string isbn() const;
	virtual double net_price(std::size_t n) const;	//返回书籍实际销售价格
};

class Bulk_quote: public Quote{
public:
    double net_price(std::size_t) const override;
};
```

派生类在内部对虚函数进行声明，在最后加override表示覆盖



- 当我们使用基类的引用或指针调用一个虚函数将发生**动态绑定**，函数版本由该引用或指针决定

- 基类应定义一个虚析构函数以实现动态绑定

- ==virutal只出现在类内部的声明语句之前==

派生类的成员函数不一定有权访问基类的成员。派生类能访问public和**protected**

一个派生类对象含有派生类单独定义的成员和继承自基类的成员。后者允许我们把派生类对象当基类对象使用或**将基类引用或指针绑定到派生类对象上**

```cpp
//从派生类到基类的类型转换
BUlk_quote bulk;
Quote &r = bulk;		//r绑定到bulk的Quote部分
```

**派生类构造函数**

必须使用基类构造函数初始化它的基类部分

有时我们不希望其他类继承某个类，我们在之后加上`final`防止继承发生	

如：`class Noderived final{};` `class Last final: public Base{};`

派生类的声明不含派生类列表	`class Bulk_quote;`



#### 类型转换与继承

静态类型：编译时已知，是变量声明或表达式生成的类型

动态类型：运行时才知，是内存中实际存在类型

如果 表达式 不是指针或引用，则动静态类型永远一致



不存在基类向派生类的隐式类型转换

```cpp
Quote base;
Bulk_quote *q = &base;	//wrong
Bulk_quote &r = base;	//wrong

//下述赋值过程bulk的Bulk_quote部分将被切掉
Bulk_quote bulk;
Quote item(bulk);	//调用Quote::Quote(const Quote&)
item = bulk;		//调用Quote::operator=(const Quote &);
```



#### 虚函数

必须为每个虚函数都提供定义，因为编译器也不知道具体变量会使用哪个版本

将要覆盖的函数定义加上override使编译器帮助检查是否声明有误	加上final防止进一步覆盖



使用作用域运算符回避虚函数机制（动态绑定）`double undiscounted = baseP->Quote::net_price(42);`

通常当一个派生类的虚函数调用它覆盖的基类的虚函数版本时，基类的版本完成继承层次中所有类型都要做的共同任务，我们需要回避虚函数机制



#### 抽象基类
有时我们希望某个类表示通用的概念，而非具体的策略。我们将虚函数定义成纯虚的
```cpp
class Disc_quote{
public;
    Disc_quote() = default;
    Disc_quote(const std::string book, double p
               std::size_t n, double disc):
               Quote(book, p), 
               quantity(n), discount(disc) {}
    double net_price(std::size_t n) const = 0;
protected:
    std::size_t quantity = 0;
    double discount = 0.0;    
};
```


尽管抽象基类不能定义对象，但我们仍为它定义构造函数，为使后面的派生类函数使用其构造Disc_quote部分
含有纯虚函数的类是**抽象基类**，抽象基类负责定义接口
在Quote的继承体系中加入Disc_quote是**重构**的典型

> 重构负责重新设计类的体系

#### 访问继承与控制

受保护的成员
- 和私有成员类似，受保护成员对类的用户来说不可访问
- 和公有成员类似，受保护成员对派生类的成员和友元可访问
- 派生类成员或友元只能通过**派生类对象**访问基类受保护成员，派生类对基类中的protected成员没有任何访问特权（不能通过基类对象访问）

某个类对其继承而来的成员的访问权限受两个因素影响：基类中该成员的访问说明符，派生类派生列表中的访问说明符
派生类的访问说明符：决定从基类继承而来的成员在本类中的权限
如：`class D: private Base{};`  这样的话D的派生类对象将不能访问Base的所有成员
后者的一个例子：$p_{544}$

> 不考虑继承，一个类有两种用户：普通用户、类的实现者
> 一个类普通用户编写代码使用类的对象，这部分代码只能访问类的公有接口；
> 实现者负责编写类的成员和友元的代码间接访问类的私有部分   
> 基类应该将接口成员分为两组：一组供派生类访问，另一类只能由基类及基类友元访问；前者声明为protected，后者声明为private

使用using声明改变派生类继承某个成员的权限
```cpp
class Derived: private Base{
public:
    using Base::n;
provted:
    using Base::size;
};
```

#### 继承中的类作用域

派生类的作用域嵌套在基类作用域中。如果一个名字无法在派生类作用域中正确解析，编译器继续在外围基类作用域中寻找该名字的定义

在编译时进行名字查找取决于该对象的静态类型，如：
```cpp
class Disc_quote{
public:
    … discount_policy() const {…}
};
Bulk_quote bulk;
Bulk_quote *bulkp = &bulk;  //静态动态类型一致
Quote *itemp = &bulk;       //静态与动态类型不一致
bulkp->discount_policy();   //right 
itempp->discount_policy();  //wrong itemp类型是Quote*
```
itemp指向Quote 意味着对discount_policy的搜索从Quote开始，所以找不到该成员

**名字查找步骤**
假定我们调用p->mem()
1. 确定p的静态类型
2. 在其中查找mem 如找不到则一次在直接基类中不断查找直到继承链顶端
3. 找到 进行常规类型检查 调用是否合法
4. 根据是否是虚函数产生不同的代码：
   - 动态绑定
   - 常规函数调用

#### 构造函数与拷贝控制
基类需要一个虚析构函数，每一个派生类继承其虚析构函数以使动态与静态类型不一致的引用或指针正确地析构
对于派生类的合成函数，它会不断调用直接基类的相应合成函数，依次类推完成函数

在默认情况下，基类默认构造函数初始化派生类对象的基类部分。如果我们想拷贝（或移动）基类部分则必须在派生类的构造函数初始值列表中显示地使用基类的拷贝（或移动）构造函数。
如   
```cpp
class D: public Base {
public:
    D(const D& d): Base(d)
    {…}
    D(D&& d): Base(std::move(d))
    {…}
};

//Base::operator=(const Base &)
D& D::operator=(const D &rhs){
    //Base的拷贝赋值运算符是合成的还是定义的无关紧要
    Base::operator=(rhs);
    //…
    return *this；
}
```
派生类的析构函数只负责析构派生类的部分


派生类能直接继承其**直接基类**的构造函数
注意：不能继承默认、拷贝和移动构造函数
我们使用using声明继承构造函数
```cpp
class Bulk_quote: public Disc_quote{
public:
    using Disc_quote::Disc_quote;   //继承Disc_quote的构造函数
};
//等价于
Bulk_quote(const std::string &book, double p,
           std::size_t n, double disc):
           Disc_quote(book, p, n, disc){}
```
与普通成员的using声明不同，构造函数的using不会改变构造函数的访问权限 如：基类的私有构造函数在派生类中继承仍是私有



