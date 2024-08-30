1. 修饰变量的时候，可以把 constexpr 对象当作加强版的 const 对象：const 对象表明值不会改变，但不一定能够在编译期取得结果；constexpr 对象不仅值不会改变，而且保证能够在编译期取得结果。如果一个 const 变量能够在编译期求值，将其改为 constexpr 能够让代码更清晰易读。
2. constexpr 函数可以把运行期计算迁移至编译期，使得程序运行更快（但会增加编译时间）。但如果 constexpr 函数中存在无法在编译期求值的参数，则 constexpr 函数和普通一样在运行时求值，此时的返回值不是常量表达式。


[一文总结现代 C++ 中的初始化](https://www.cnblogs.com/tengzijian/p/18018104)