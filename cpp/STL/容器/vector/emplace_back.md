push_back参数是左值时，将参数拷贝到vector中；参数是右值时，调用emplace_back在vector尾直接构造元素（可能是拷贝，也可能是移动，取决于对应元素类型有没有实现移动构造函数）。

大部分情况下，其实`emplace_back`和`push_back`相同，下面这种情况不相同。
```cpp
    // 先根据666构造一个临时Item，再内部调用emplace_back在vector尾直接构造元素（拷贝/移动）。
    v.push_back(Item(666));  

    //根据666直接在vector尾构造元素。
    v.emplace_back(666);
```

所以对于这种情况（构造一个临时对象然后push_back到vector中），使用`emplace_back`函数可以减少一次拷贝或移动构造的过程。


### 参考

[emplace_back更好？能完美替代push_back吗？](https://www.bilibili.com/video/BV1Pp4y1P7A8/?spm_id_from=333.337.search-card.all.click&vd_source=290e10e6da0d78fd6c632cdb3be20ba1)  
[C++11_emplace_back的优点](https://www.jianshu.com/p/1fb2daf66582)