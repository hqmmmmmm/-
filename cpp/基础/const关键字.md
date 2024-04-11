const与函数重载？


1.const用于成员函数，在函数尾部加const可以实现重载。

2.const用于非成员函数，在函数参数加const，并且参数是指针或引用类型时可以实现重载。
```cpp
void fun(int *p) { // 或者int &r
    cout << "fun() called" << endl;
}

void fun(const int *p) { // 或者const int &r
    cout << "fun() const called" << endl;
}
```
但是`fun(int i)`和`fun(const int i)`不可以重载，因为这两个都是修改不了i的，按值传递得到的是拷贝后的副本。

同理`fun(int *p)`和`fun(int *const p)`也不可以重载，因为这两个都是传参的时候都是直接拷贝指针的值，也就是指向的地址，所以都不可以改变指针的指向。

---

const修饰函数返回值，一般当函数返回值是指针或引用时，可以防止修改。

---

const只读变量和常量？

- 只有用字面量初始化的 const 常量才会进入符号表(进入符号表会做优化，在编译时会直接替换为对应常量)
- 使用其他变量初始化的 const 常量仍然是只读变量
- 被 volatile 修饰的 const 常量不会进入符号表

综上所述，在编译期间不能直接确定初始值的`const`标示符，都被作为只读变量处理。

当 const 修饰的变量是只读变量时，仅仅是说明不能通过这个只读变量修改内存的值，但是可以通过其他方法修改内存值。
