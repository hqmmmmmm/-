#include <iostream>

class Singleton {
public:
    static Singleton &GetInstance() {
        static Singleton inst;
        return inst;
    }

    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;

private:
    Singleton() {}
};

