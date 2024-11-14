### 如何实现引用计数？
- 每个智能指针内部都有一个计数器，其实就是一个指针，指向堆上的一块空间，引用计数就存放在这个堆空间上，这样指向同一个对象的智能指针就能共享一个引用计数了。
- 如果使用计数器直接使用一个int型变量的话，相当于指向同一个对象的两个智能指针的计数器却是指向不同的栈空间，引用计数发生变化，另一个智能指针也感受不到这个变化不能及时更新；
- 如果使用static变量也不行，static变量是属于类的，那样所有的智能指针都是共享同一个引用计数，更不合理。

### 循环引用

### enable_shared_from_this
> 简单地说就是帮助你怎么在class内部拿到this的shared_ptr版本。
```cpp
class A {
void func() {
  std::shared_ptr<A> local_sp_a(this);
  // do something with local_sp_a
  // func函数退出后，local_sp_a析构时查看引用计数为1，直接清理this对象。
  // enable_shared_from_this可以让返回的shared_ptr与其它管理this对象的shared_ptr共享引用计数。
}
}

int main() {
  A* a;
  std::shared_ptr<A> sp_a(a);
  a->func();
  // sp_a becomes dangling.
}
这样拿的话，表面上看起来你是拿到了一个this的shared_ptr版本，但是由于计数器和被管理的对象是分离的，因此相当于2个计数器（reference count都=1），一个被管理的对象。函数内部的那个计数器，在函数调用完成之后，认为reference count变成0了，于是释放掉了对应的object。main里构造的计数器当然不知道对应的object已经被释放了，于是就会boom。C++解决方案是通过继承一个类，这个类本质上会给被管理的object上加一个指向计数器的weak ptr，于是就可以正确地增加引用计数而不是搞出2个独立的计数器。

```