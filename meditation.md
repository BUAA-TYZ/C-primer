## 沉思录



#### chapter15 面向对象程序设计

1. 编写时获得教训，头文件放在'.h'文件中

2. 只有构造函数使用成员列表初始

3. 拷贝赋值必须另起一行（否则就是拷贝初始化了）

4. 派生类中的移动赋值运算符的编写

   ```cpp
   //这里要注意在调用直接基类的拷贝赋值时
   //编译器会将其自动转换为Disc_quote
   //但发现其会匹配到直接基类的拷贝赋值版本
   //故将rhs（这里可能已经被转换为Disc_quote）移动为右值
   //发现匹配上了Disc_quote的移动赋值
   
   Bulk_quote& Bulk_quote::operator=(Bulk_quote &&rhs){
       if(this != &rhs){
           Disc_quote::operator=(std::move(rhs));
       }   
       cout << "This is Bulk_quote move =" << endl;
       return *this;
   }
   ```

5. 尽量使用`override` 表明意图