new会调用operator new()函数，operator new()函数中会调用malloc函数，如果调用失败会抛出bad_alloc异常；
如果是类类型，还要调用类的构造函数在已分配的内存上构造对象。
