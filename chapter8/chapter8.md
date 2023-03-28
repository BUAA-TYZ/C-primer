## IO库

| 头文件     | 类型                           |
| ---------- | ------------------------------ |
| `iostream` | istream 从流读取数据           |
|            | ostream 向流写入数据           |
|            | iostream 读写流                |
| `fstream`  | ifstream 从文件读取数据        |
|            | ofstream 向文件写入数据        |
|            | fstream 读写文件               |
| `sstream`  | istringstream 从string读取数据 |
|            | ostringstream 向string写入数据 |
|            | stringstream 读写string        |

每个流都管理一个缓冲区，用来保存程序读写的数据(为了使操作系统一次写操作能写更多，(提升性能)

刷新输出缓冲区

```cpp
cout << "hi" <<endl;     //endl使用后刷新缓存区
cout << "hi" <<flush;    //刷新缓冲区不进行额外操作
cout << unitbuf;         //所有输出操作后刷新缓冲区（每一个写操作都调用flush）
cout << nounitbuf;       //回到正常
```



#### 文件输入输出

| fstream特有的操作         |                                                           |
| ------------------------- | --------------------------------------------------------- |
| `fstream fstrm; `         | 创建一个未绑定的文件流                                    |
| `fstream fstrm(s);`       | 创建一个fstream并打开名为s的文件，该构造函数是explicit的  |
| `fstream fstrm(s, mode);` | 按指定mode打开文件                                        |
| `fstrm.open(s);`          | 打开名为s的文件并将s与文件绑定                            |
| `fstrm.close();`          | 关闭与fstrm绑定的文件                                     |
| `fstrm.is_open();`        | 返回一个bool值指出与fstrm关联的文件是否成功打开且尚未关闭 |

==fstream、stringstream继承于iostream, 故允许向istream& 或ostream& 传递它们的对象==

当一个fstream对象被销毁时，close会自动被调用

| 文件模式 |                            |
| -------- | -------------------------- |
| in       | 以读方式打开               |
| out      | 以写方式打开               |
| app      | 每次写操作均定位到文件末尾 |

==以out模式打开文件会丢弃已有数据==

若要接着写需指定app模式或in模式：ostream out; out.open(s, ofstream::app);



#### string流

| stringstream特有的操作 |                                                              |
| ---------------------- | ------------------------------------------------------------ |
| `sstream strm(s);`     | strm是一个sstream对象，保存string s的一个拷贝。此构造函数是explicit的 |
| `strm.str();`          | 返回strm所保存的string的拷贝                                 |
| `strm.str(s);`         | 将string s拷贝到strm中                                       |

 使用istringstream读取数据

对于文件比如：

morgan 23123 12312

lucas 2312312

stephanie 213123123

可以

```cpp
struct PersonInfo{
    string name; 
    vector<string> phones;
}
string line, word;                                    
ifstream fstrm("PersonInfo.txt", ifstream::in);        //从文件中读取
vector<PersonInfo> people;
while(getline(fstrm, line)){
    PersonInfo temp;
    istringstream record(line);                        //创建字符流
    line >> temp.name;
    while(line >> word)
        temp.phones.push_back(word);
    people.push_back(temp);
}
```

