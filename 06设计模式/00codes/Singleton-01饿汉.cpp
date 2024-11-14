class Singleton {
public:
    static Singleton *GetInstance() {
        return inst;
    }

    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;

private:
    Singleton() {}
    static Singleton *inst;
};

// static变量必须在类外初始化
Singleton *Singleton::inst = new Singleton{};