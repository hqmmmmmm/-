#include <iostream>
using std::cout;
using std::endl;


namespace yuy77
{

class vector
{
public:
    vector(): ptr_(nullptr), size_(0), cap_(0) {}
    vector(int size): ptr_(new int(size)), size_(size), cap_(size) {}
    ~vector()
    {
        if(ptr_)
        {
            delete ptr_;
            ptr_ = nullptr;
        }
    }


    void push_back(const int &x)
    {
        if(size_ == cap_)
        {
            auto new_cap = cap_ ? 2 * cap_ : 1;
            auto new_ptr_ = new int[new_cap];

            for(int i = 0; i < cap_; ++i)
                new_ptr_[i] = ptr_[i];

            cap_ = new_cap;
            ptr_ = new_ptr_;   
        }

        ptr_[size_++] = x;
    }

    void pop_back() { size_--; }

    int size() { return size_; }
    int capacity() { return cap_; }
    bool empty() { return size_ == 0; }

    int &operator[](int i) { return ptr_[i]; }

private:
    int *ptr_;
    int size_;
    int cap_;
};


}



int main()
{
    yuy77::vector v;
    for(int i = 0; i < 10; ++i)
        v.push_back(i);

    cout << v.size() << " " << v.capacity() << endl;
    
    for(int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;


    return 0;
}