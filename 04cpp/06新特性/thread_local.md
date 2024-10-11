thread_local是c++11为了线程安全引入的变量声明符，它指示对象具有线程存储期，即在线程开始时创建，在线程结束时销毁，每个线程有其自身的对象实例。




全局变量：

局部变量：

类对象：

类成员变量：thread_local修饰类成员变量时必须为static



https://blog.csdn.net/zhizhengguan/article/details/109737834