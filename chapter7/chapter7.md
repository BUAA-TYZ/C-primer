## chapter7
类内初始值
```c
struct Sales_data{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    }
```
默认构造函数
构造函数初始值列表
>对于不在列表中的成员则优先执行类内初始化，若无则默认初始化。（于合成的默认构造函数行为相同）
```c
Sale_data() = default;
sales_data(const std::string &s, unsigned n, double p): 
bookNo(s), units_sold(n), revenue(p*n){}
```
*注意：*this返回一个对象的引用**

#### 访问控制与封装
访问说明符
> private : 定义的成员可以被类的成员函数访问

> public  : 定义的成员在整个程序内可被访问，public的成员定义类的接口

友元
> 类可以允许其他类或者函数访问它的非公有成员

>最好在类定义的开始或结束前集中声明友元
```c
class Sales_data{
    friend std::ostream &print(std::ostream, const Sales_data);
    friend void M::clear();
    friend class M;
}

```
$p_{248}$ : 对一个函数的常量版本和非常量版本，倾向于编写一个函数放在private, 供public中的两个版本进行引用
可以令类的某个成员函数, 某个类成为友元

#### 隐式的类类型转换
如果构造函数只接受一个实参，则它实际上定义了转换为此类型的隐式转换机制
```c
string null_book = “9-999-99999-9”;
item.combine(null_book);  //正确
item.combine(“9-999-99999-9”);  //错误，只允许一步类类型转换
```
**抑制构造函数定义的隐式转换**
使用**explicit**关键字
该关键字只对一个实参的构造函数有用。需要多个实参的构造函数不能用于隐式转换，故无需explicit.但仍可以显示进行转换！
```c
explicit Sales_data(const std::string &s): bookNo(s){};
item.combine(null_book);  //错误，被抑制
item.combine(Sales_data(null_book));  //正确，显示进行了转换
```

#### 类的静态成员
> 有时，类需要它的一些成员与类本身直接相关，而与类的各个对象无关。如一个银行账户类可能需要一个数据成员来表示当前的基准利率。
```cpp
class Account{
public: 
    ...
private:
    std::string owner;
    double amount;
    static double interestRate;
    static double initRate();
}
```
类的静态成员存在于任何对象之外。每个Account成员包含两个数据成员：owner amount。只存在**一个interestRate**对象且被所有Account成员共享。

在类作用域外使用作用域运算符直接访问静态成员 ｜成员函数不用通过作用域运算符直接使用静态成员 