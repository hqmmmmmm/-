## 1.std::optional是什么
C++17新特性。表示一个可能有值的对象，没有值时就是`std::nullopt`。


## 2.为什么引入std::optional
因为C++底层缺少None这个表示，所以将`std::nullopt`和某种特定类型的变量合并在一起构造成一个`std::optional`对象。

比如实现返回数组中第一个非0元素的函数，当数组中不存在非0元素时返回-1，但是其实我们不知道这个-1是表示第一个非0元素还是说数组中不存在非0元素。这时候使用`std::optional`就比较不方便，不存在时直接返回`std::nullopt`。
```cpp
std::optional<int> func(vector<int> &nums) {
    for(auto &num : nums) {
        if(num) {
            return num;
        }
    }
    return std::nullopt;
}
```


## 3.std::optional的构造
```cpp
// 构造
std::optional<int> opt1(1);
std::optional<int> opt2 =  std::make_optional(2);
// 每次调用emplace 时，会清除掉之前的值
opt1.emplace(11);
```


## 4.std::optional判断是否有值
```cpp
if(opt1.has_value()) {
    // 通过has_value()判断
}
if(opt1 != std::nullopt) {
    // 通过是否等于std::nullopt判断
}
if(opt1) {
    // 直接if判断，因为重载了operator bool.
}
```


## 5.std::optional获取值
```cpp
if(opt1) { // 通过value成员函数
    cout << opt1.value() << endl;
}
if(opt1) { // 通过*运算符
    cout << *opt1 << endl;
}
```
当`std::optional`中不存在值，即`std::nullopt`时，调用`value`成员函数会抛异常`std::bad_optional_access`, 可以使用`value_or()`.
```cpp
// 设置默认值为-1，即当opt1中不存在值时，value_or会返回-1
cout << opt1.value_or(-1) << endl; 
```


## 6.使用std::optional进行错误处理

在C++17之前，大概有两种错误处理的方式：错误码和抛异常。

```cpp
// 错误码，通过值-结果参数来传出结果
ErrCode function(Input in, Output &out)
{
    // do some work & fill result to out
    if(error) {
        return ErrCode::ErrorType;
    }
    return ErrCode::Success;
}

// 抛异常，发生错误时抛异常，未发生错误时直接返回结果
Output function(Input in)
{
    Output out;
    // do some work & fill result to out
    if(error) {
        throw my_exception("Error: Error Type.");
    }
    return out;
}
```

使用`std::optional`
```cpp
std::optional<int> MyDiv(int a, int b)
{
    std::optional<int> ret = std::nullopt;
    if(b == 0) {
        return ret;
    }

    ret = a / b;
    return ret;
}

int main() 
{
    int a = 1, b = 2;
    std::optional<int> ret = MyDiv(1, 0);
    if(ret) {
        cout << *ret << endl;
    } else {
        cout << "div error" << endl;
    }
}
```



## 7.参考
[C++ std::optional 使用教程](https://zhuanlan.zhihu.com/p/639111975)

[[C++17]使用std::optional进行错误处理](https://www.bilibili.com/video/BV1nL4y1a75t/?spm_id_from=333.337.search-card.all.click&vd_source=290e10e6da0d78fd6c632cdb3be20ba1)
