## chapter3 字符串、向量和数组

#### 字符串

定义和初始化string

```c
string s1;            
string s1(s2);
string s2 = s1;
string s3("value");
string s3 = "value";
string s4(n, 'c');        //连续n个字符c
//有等号为拷贝初始化，否则为直接初始化
```

string的操作

```c
os<<s;
is>>s;
getline(is, s);     //从is读一行(直至遇到换行符并从缓冲区中读出换行符并舍弃)给s，返回is
s.empty();
s.size();
s[n];s.at(n);
s1 + s2;
s1 = s2;
s1 == s2 != <= >= < >
```

string::size_type **无符号**整型

一些用于处理字符的函数

```c
#include<cctype>
isalnum(c);   //c是字母或数字时为真
isalpha(c);
isdigit(c);
isspace(c);
islower(c);   //c是小写字母时为真
isupper(c);
```

使用范围for处理字符串中所有字符

若要处理某些字符，采用迭代器或下标的方法

```c
for(auto p: str);   //将str每个字符拷贝给p
for(auto& p: str);
```



#### 动态数组

定义和初始化vector

```c
vector<T> v1;
vector<T> v2(v1);
vector<T> v2 = v1;
vector<T> v3(n, val);
vector<T> v4(n);         //n个执行了值初始化的对象
vector<T> v5{a, b, ...};
vector<T> v5 = {a, b, ...};
v1.push_back(p);         //末尾添加
```

后两种称为**列表初始化** 若提供一个初始元素值的列表则只能列表初始化

vector<int> 值初始化为0

vector<int> size::type   正确	vector size::type  错误！！



#### 迭代器

迭代器的类型(不在意)

vector<int>::iterator 

string iterator

vector<int>::const_iterator 只可读不可写

```c
auto e = v.end();  //end()返回一个尾后迭代器
```

迭代器的运算符

```c
*iter;        //返回迭代器iter所指元素的引用
iter->man;
++iter;
--iter;
== !=
```

  **向一个动态增长的容器添加元素可能使迭代器失效**



#### 数组

定义和初始化数组

允许列表初始化

```c
int a1[] = {0, 1};
int a2[5] = {0, 1};   //等价于 int a2[] = {0, 1, 0, 0, 0};
```

**不允许用一个数组拷贝或赋值另一个数组**

```c
int *ptr[10];                //ptr是含十个指针的数组(由右向左)
int (*Parray)[10] = &arr;    //Parray是一个指向含十个int的数组的指针(由内向外)
int (&arrRef)[10] = arr;     //是一个对含十个int的数组的引用
```



