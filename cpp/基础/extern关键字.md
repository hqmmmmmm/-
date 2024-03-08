extern修饰变量：当需要在一个文件中引用另一个文件中的变量a时，就可以使用extern修饰，extern int a;

extern修饰函数：当需要在一个文件中引用另一个文件中的函数func时，就可以使用extern修饰，extern int func();
默认情况情况下函数都是extern的, 除非使用static对函数进行了隐匿

extern "C"：当需要在C++程序中使用C语言编译而成的函数时，就需要使用extern "C"声明这个函数，告诉链接器链接的时候使用C函数规范来链接，主要是C++和C语言编译生成函数名的规则不同。