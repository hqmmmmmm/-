#include <iostream>
#include <vector>


class AbstractObserver;

class Cat 
{
public:
    void attach(AbstractObserver *observer) {
        observers_.push_back(observer);
    }

    void detach(AbstractObserver *observer) {
        for(auto it = observers_.begin(); it != observers_.end(); ++it) {
            if(*it == observer) {
                observers_.erase(it);
                break;
            }
        }
    }

    void cry() {
        for(auto observer : observers_) {
            observer->response();
        }
    }

private:
    std::vector<AbstractObserver *> observers_; 
};


class AbstractObserver 
{
public:
    virtual void response() = 0;
};

class Dog: public AbstractObserver
{
public:
    void response() override {
        std::cout << "狗追猫" << std::endl;
    }
};

class Mouse: public AbstractObserver
{
public:
    void response() override {
        std::cout << "猫追老鼠" << std::endl;
    }
};

int main()
{
    // 发布者
    Cat cat;
    
    // 观察者
    Dog dog;
    Mouse mouse;

    cat.attach(&dog);
    cat.attach(&mouse);

    cat.cry();


    return 0;
}