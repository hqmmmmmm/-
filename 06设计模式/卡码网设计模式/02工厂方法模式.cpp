#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Block {
public:
    virtual string get_name() = 0;
};

class circleBlock: public Block {
public:
    string get_name() {
        return "Circle Block";
    }
};

class squareBlock: public Block {
public:
    string get_name() {
        return "Square Block";
    }
}; 


class Factory {
public:
    virtual shared_ptr<Block> produce() = 0;
};

class circleFactory: public Factory {
public:
    shared_ptr<Block> produce() {
        return std::make_shared<circleBlock>();
    }
};

class squareFactory: public Factory {
public:
    shared_ptr<Block> produce() {
        return std::make_shared<squareBlock>();
    }
};

unordered_map<string, shared_ptr<

int main() {
    shared_ptr<Factory> factory;
    shared_ptr<Block> block;

    int n; cin >> n;
    while(n--) {
        string str; int cnt;
        cin >> str >> cnt;
        if(str == "Circle") {
            factory = make_shared<circleFactory>();
        } else {
            factory = make_shared<squareFactory>();
        }
        while(cnt--) {
            block = factory->produce();
            cout << block->get_name() << endl;
        }
    }

    return 0;
}