### RAII (Resource Acquisition Is Initialization)
资源获取即初始化，C++中一种管理资源、避免资源泄露的惯用法，利用栈对象自动销毁的特点来实现，在构造函数中获取资源，在析构函数中释放资源。