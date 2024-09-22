#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

struct student
{
    std::string name;
    int age = 1;
    char sex;
};

class A
{
private:
    int a, b;
public:
    void fun() {}
    // virtual void dosome() {}
    // virtual void getsome() {}
};

int main() {
    cout << sizeof(A) << endl;


    return 0;
}
// 函数返回一个数组