volatile是C语言中的一个关键字，当一个变量被volatile修饰时，编译器会禁止对该变量进行优化，当访问变量时都会从内存中取值，不会从寄存器或缓存中取。

---

volatile可以和const一起用吗？

可以，const表示代码不能对变量进行修改，和volatile不冲突。