## 1.union
union联合体，可以存储多种类型的数据，但是任意时刻只有一种类型的数据存储在内存中，当写入新的数据时，原来的数据会被覆盖。联合体的大小是其中所有类型占用空间最大的那个。  
union缺点：union不知道当前存储的数据的类型，并且不能正确调用构造和析构函数，无法存储复杂的数据类型。


## 2.std::variant
类模板 std::variant 表示一个类型安全的联合体.
```cpp
    // 初始化
    std::variant<int, std::string, double> v(123);

    // 修改
    v = "HelloWorld";

    // 判断variant中对应类型是否有值
    if(std::holds_alternative<std::string>(v)) {
        cout << "has std::string" << endl;
    }

    // 获取std::variant中的值
    cout << std::get<std::string>(v) << endl;
    cout << std::get<1>(v) << endl;  // 下标从0开始

    // 当variant中不存在值时，调用std::get会抛异常std::bad_variant_access
    // std::get_if()要自行判断返回的指针类型是否为空，不会抛异常
    if(auto str = std::get_if<std::string>(&v)) {
        cout << *str << endl;
    }

    // 获取当前使用的type 在variant声明中的索引
    cout << v.index() << endl;
```


## 3.std::visit配合std::variant使用，对于variant中数据不同的类型进行不同的操作
通过type_traits实现：
```cpp
    std::variant<int, std::string, bool> v(666);
    
    // 配合std::visit使用。
    // 第一个参数是一个可调用对象，要求支持参数类型为variant中的所有类型，会对variant中的值调用这个可调用对象
    std::visit([](auto &&arg) {
        using type = std::decay_t<decltype(arg)>;
        if constexpr (std::is_same_v<type, int>) {
            cout << "type = int, value = " << arg << endl;
        } 
        else if constexpr (std::is_same_v<type, std::string>) {
            cout << "type = std::string, value = " << arg << endl;
        } 
        else if constexpr (std::is_same_v<type, bool>) {
            cout << "type = bool, value = " << arg << endl;
        }
    }, v);
```

通过函数重载实现。
（TODO）


## 4.参考
[Modern C++真的很烂——std::variant](https://zhuanlan.zhihu.com/p/645810896)  
[[C++ STL] C++17知识点 比union更简单 实用的可变体 std::variant](https://www.bilibili.com/video/BV1Ae4y1t7AJ/?spm_id_from=333.999.0.0&vd_source=290e10e6da0d78fd6c632cdb3be20ba1)  
[[C++ STL]C++17 之 std::visit 配合 std::variant使用](https://www.bilibili.com/video/BV1Sd4y1r759/?spm_id_from=333.999.0.0&vd_source=290e10e6da0d78fd6c632cdb3be20ba1)