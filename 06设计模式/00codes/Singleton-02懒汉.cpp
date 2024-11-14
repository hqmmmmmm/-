#include <mutex>

class Singleton {
public:
    static Singleton *GetInstance() {
        if(inst == nullptr) {
            std::unique_lock<std::mutex> lock(mtx);
            if(inst == nullptr) {
                inst = new Singleton{};
            }
        }
        return inst;
    }

private:
    Singleton() {}
    static Singleton *inst;
    static std::mutex mtx;
};

Singleton *Singleton::inst = nullptr;
std::mutex Singleton::mtx;