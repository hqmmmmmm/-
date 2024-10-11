const使用场景

1.const变量
2.const与指针
3.const与引用
4.const成员函数

---

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

const只读变量和常量？

在编译期间不能直接确定初始值的`const`标示符，都被作为只读变量处理。当const表示的是常量时，编译器可能会进行优化，直接将对应const变量替换成值。

当 const 修饰的变量是只读变量时，仅仅是说明不能通过这个只读变量修改内存的值，但是可以通过其他方法修改内存值。
当const修饰的变量是常量时，如果是局部变量，存在栈中，还是可以通过const_cast修改；如果是全局变量，存在.rodata，修改的话程序会崩溃。