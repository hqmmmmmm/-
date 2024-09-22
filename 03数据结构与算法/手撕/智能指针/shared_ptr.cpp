// 2024/5/25/0025.

#include <utility>

namespace yuy {
    class ref_count {
    public:
        int use_count() const { return count_; }
        void inc_ref() { ++count_; }
        int dec_ref() { return --count_; }
    private:
        int count_{1};
    };

    template<typename T>
    class shared_ptr {
    public:
        explicit shared_ptr(T *ptr = nullptr);   // 默认构造与有参数构造函数结合
        ~shared_ptr();                           // 析构函数

        shared_ptr(const shared_ptr<T> &rhs);                // 拷贝构造函数
        shared_ptr<T> &operator=(const shared_ptr<T> &rhs);  // 拷贝赋值运算符

        shared_ptr(shared_ptr<T> &&rhs) noexcept;                 // 移动构造函数
        shared_ptr<T> &operator=(shared_ptr<T> &&rhs) noexcept;   // 移动赋值运算符

        void swap(shared_ptr<T> &rhs);  // 交换两个shared_ptr
        void reset();
        void reset(T *ptr);

        T *get() const;         // 返回原始指针
        T &operator*() const;   // 重载*
        T *operator->() const;  // 重载->

        int use_count() const;             // 返回引用计数
        bool unique() const;               // 引用计数是否为1
        explicit operator bool() const;    //

    private:
        T *ptr_{nullptr};
        ref_count *rep_{nullptr};
    };




    template<typename T>  // 默认参数一般在声明中出现，在定义中不能再出现
    shared_ptr<T>::shared_ptr(T *ptr): ptr_(ptr) {
        if(ptr) {
            rep_ = new ref_count{};
        }
    }

    template<typename T>
    shared_ptr<T>::~shared_ptr() {
        if(rep_ && !rep_->dec_ref()) {
            delete ptr_;
            delete rep_;
        }
    }

    template<typename T>
    shared_ptr<T>::shared_ptr(const shared_ptr<T> &rhs): ptr_(rhs.ptr_), rep_(rhs.rep_) {
        if(rep_) {
            rep_->inc_ref();
        }
    }

    // 这个过程中rhs引用计数会先自增，然后this指向rhs，临时对象销毁时会让之前this指向的shared_ptr引用计数-1
    // 可以理解为：临时对象构造的过程负责赋值的操作，临时对象析构的过程负责“善后”的工作。
    template<typename T>
    shared_ptr<T> &shared_ptr<T>::operator=(const shared_ptr<T> &rhs) {
        shared_ptr{ rhs }.swap(*this);
        return *this;
    }


    template<typename T>
    shared_ptr<T>::shared_ptr(shared_ptr<T> &&rhs) noexcept: ptr_(rhs.ptr_), rep_(rhs.rep_) {
        rhs.ptr_ = nullptr;
        rhs.rep_ = nullptr;
    }


    template<typename T>
    shared_ptr<T> &shared_ptr<T>::operator=(shared_ptr<T> &&rhs) noexcept{
        shared_ptr{ std::move(rhs) }.swap(*this);
        return *this;
    }

    template<typename T>
    void shared_ptr<T>::swap(shared_ptr<T> &rhs) {
        std::swap(ptr_, rhs.ptr_);
        std::swap(rep_, rhs.rep_);
    }

    template<typename T>
    void shared_ptr<T>::reset() {
        shared_ptr{}.swap(*this);
    }

    template<typename T>
    void shared_ptr<T>::reset(T *ptr) {
        shared_ptr{ ptr }.swap(*this);
    }

    template<typename T>
    T *shared_ptr<T>::get() const {
        return ptr_;
    }

    template<typename T>
    T &shared_ptr<T>::operator*() const {
        return *ptr_;
    }

    template<typename T>  // sp->m被解释为(sp.operator->())->m, 所以重载->运算符必须返回指针
    T *shared_ptr<T>::operator->() const {
        return ptr_;
    }

    template<typename T>
    int shared_ptr<T>::use_count() const {
        return rep_ ? rep_->use_count() : 0;
    }

    template<typename T>
    bool shared_ptr<T>::unique() const {
        return use_count() == 1;
    }

    template<typename T> // 类型转换函数
    shared_ptr<T>::operator bool() const {
        return static_cast<bool>(ptr_);
    }

}


