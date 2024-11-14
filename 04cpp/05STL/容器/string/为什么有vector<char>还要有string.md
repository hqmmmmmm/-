string用来表示动态变化的堆上的字符串，能跟C语言中的以'\0'结尾的字符串兼容，而vector<char>实际不是一个字符串，只不过是一个用char类型实例化的容器，比如我们某个函数需要一个字符串，如果想传入vector<char>的话，还要再手工在末尾push_back一个'\0'，再把data指针传过去。

[c++中，char类型数组、string字符串、char的vector，为什么不能统一](https://www.zhihu.com/question/614596735/answer/3141553992)