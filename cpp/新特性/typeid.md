typeid返回typeinfo类型的对象，我们可以通过这个对象获取变量、函数、指针等的类型信息。（运行时）

```cpp
#include <iostream>
#include <typeinfo>
using namespace std;
int main() {
    int a = 1;
    // 判断变量类型是否为指定类型
    if(typeid(a) == typeid(int)) {
        cout << "int" << endl;
    }
    // 输出变量类型名，不同编译器结果不同，只要求在一个编译器上同一类型输出相同
    cout << typeid(a).name() << endl;

    return 0;
}
```

typeid作用于引用类型和普通类型返回结果相同，即`typeid(int)`与`typeid(int &)`相同。


[[现代C++入门到进阶] 使用typeid进行运行时类型识别（RTTI）](https://www.bilibili.com/video/BV1Vg411Y71q/?spm_id_from=333.999.0.0&vd_source=290e10e6da0d78fd6c632cdb3be20ba1)