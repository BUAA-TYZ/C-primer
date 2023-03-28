## 重载运算与类型转换



**明智**使用运算符重载：

- 较清晰反应符号意义。如string重载的'+'
- 不滥用运算符重载
- 不应产生二义性

注意：具有对称性的运算符可能转换任意一端的运算对象，例如算术、相等性运算符等等，这时使用友元函数重载

#### 类设计的一些建议

- 输出运算符负责打印对象而非控制格式，不应打印换行符！
- 当读取发生错误，输入运算符应该负责从错误中恢复！
- 相等运算符体现出设计准则：$p_{498}$
- 如果存在唯一一种逻辑可靠的<定义，应该考虑为类定义<运算符。如果类还包含==，二者定义产生结果必须一致
- 下标运算符必须是成员函数，通常返回访问元素的引用。最好同时定义下标运算符的常量及非常量版本以防止 我们对引用做出改动（当我们不希望这么做时）

```cpp
class Strvec{
public:
    std::string& operator[](std::size_t n)
    {return elements[n];}
    const std::string& operator[](std::size_t n) const
    {return elements[n];}
    …
private:
    std::string *elements;
};
const Strvec cvec = svec;
if(svec.size() && svec.empty()){
    svec[0] = “zero”;   //right
    cvec[0] = “zip”;    //wrong cvec[0] returns a const reference     
}
```
- 递增递减运算符应该同时定义前置和后置版本
为了保持一致，前置运算符应该返回递增或递减后的**引用**。后置返回之前的**值**
注意后置版本中多了一个int形参，其唯一作用就是区分前置后置版本
```cpp
class Strblobptr{
public:
    Strblobptr& operator++(){
        check(curr, “increment past end of Strblobptr”);
        ++curr;
        return *this;
    }
    Strblobptr operator++(int){
    //here donot need to check cause we check the vadility in ++(*this);
        Strblobptr temp = *this;
        ++(*this);
        return temp;
    }
}; 
```

#### 函数调用运算符
函数调用运算符必须是成员函数，一个类可以定义多个版本的函数调用运算符
```cpp
struct absInt{
    int operator()(int val) const{
        return val < 0 ? -val: val;
       }
};
absInt absObj;
int ui = absObj(-42);
```
如果类定义了调用运算符，则该类的对象称为函数对象    callable
且这种函数对象可以作为**范型算法的实参**

**lambda**是函数对象
```cpp
auto p = [](const string &a, const string &b){return a.size()<b.size();};
//equal to
class Shorterstring{
    public:
        bool operator()(consst string &a, const string &b) const
        {return a.size()<b.size();}
};
```
标准库定义的函数对象
定义在functional头文件中
相关细节：$p_{510}$



####  重载、类型转换与运算符

 类型转换运算符`operator type() const;` type可以是任何函数能返回的类型

一个类类型转换函数必须是类的成员函数，它不声明返回类型，形参列表也必须为空。通常应是const的

尽量避免使用类类型转换运算符

它可能带来二义性问题