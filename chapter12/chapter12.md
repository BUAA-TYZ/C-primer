## 动态内存

程序用**堆**来存储动态分配的对象

`#include<memory>` 提供了两种智能指针：`shared_ptr<T>, unique_ptr<T>`

| shared_ptr<T>, unique_ptr<T>都支持的操作 |                                              |
| ---------------------------------------- | -------------------------------------------- |
| `p`                                      | 将p用作一个条件判断，若p指向一个对象则为true |
| `*p `                                    | 解引用p，获得它指向的对象                    |
| `p->mem`                                 |                                              |
| `p.get()`                                | 返回p中保存的指针，小心使用！！              |

| shared_ptr<T> 独有操作 |                                                              |
| ---------------------- | ------------------------------------------------------------ |
| `make_shared<T>(args)` | 返回一个shared_ptr, 指向一个动态分配的类型为T的对象，使用args初始化此对象 |
| `shared_ptr<T> p(q)`   | p是shared_ptr q的拷贝，此操作会递增q中的计数器，q中指针必须能转换为T* |
| `p = q`                | p和q都是shared_ptr，所保存指针必须能相互转换，此操作递减p的引用计数，递增q的引用计数 |
| `p.unique()`           | 若p的use_count()返回1则为true，否则为false                   |
| `p.use_count()`        | 返回与p共享对象的智能指针引用量                              |

程序使用动态内存基于以下三种原因之一：

1. 程序不知道自己需要使用多少对象
2. 程序不知道所需对象的准确类型
3. 程序需要在多个对象间共享数据

**定义一个[StrBlob类](./StrBlob/StrBlob.h)用于管理string**

用vector保存元素，但不能在Blob对象内直接保存元素，因为一个对象的成员在对象销毁时也会销毁，但多个Blob间应该共享这个vector。故将vector放在动态内存中，考虑使用智能指针

| 定义和改变shared_ptr的其他方法 |                                                            |
| ------------------------------ | ---------------------------------------------------------- |
| `shared_ptr<T> p(q)`           | p管理内置指针p所指向的对象；q指向new分配的内存且能转换成T* |
| `shared_ptr<T> p(u)`           | p从unique_ptr接管对象所有权                                |
| `shared_ptr<T> p(q, d)`        | ...p将调用d代替delete                                      |
| `shared_ptr<T> p(p2, d)`       | ...p将调用d代替delete                                      |

`shared_ptr<int> p(new int(42));`必须直接初始化

==`shared_ptr`使用开销较大，谨慎使用==



**`unique_ptr`**

一个时刻只能有一个unique_ptr指向一个给定对象

初始化必须直接初始化，将其绑定到一个new指针上



| unique_ptr操作          |                                                             |
| ----------------------- | ----------------------------------------------------------- |
| `unique_ptr<T> u1`      | 空unique_ptr可以指向类型为T的对象，调用delete释放它的指针、 |
| `unique_ptr<T, D> u(d)` | 空unique_ptr,用类型为D的对象d代替delete                     |
| `u = nullptr`           | 释放对象，将u置空                                           |
| `u.release()`           | u放弃对指针控制权，返回指针并将u置空                        |
| `u.reset(q)`            | 如提供了内置指针q，令u指向q,并释放原来指向的对象            |

```cpp
unique_ptr<string> p2(p1.release());
unique_ptr<string> p3(new string("Trex"));
p2.reset(p3.release());   //reset释放了p2原来指向的内存

p2.release();             //错误，p2不会释放内存，而且我们丢失了指针
auto p = p2.release();
...
delete p;
```



**`weak_ptr` 及`allocator`类**

...



[文本查询程序](./search)
