#include <iostream>
using namespace std;

namespace yuy
{
    class shared_ptr
    {
    public:
        shared_ptr() : a_(0) {}
        shared_ptr(int a) : a_(a) {}

    private:
        int a_;
    };
}

int main()
{
    cout << "helloworld" << endl;

    

    return 0;
}