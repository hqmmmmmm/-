class MyQueue {
public:
    stack<int> stk1, stk2;

    MyQueue() {

    }
    
    void push(int x) {
        stk1.push(x);
    }
    
    int pop() {
        int ret = peek();
        stk2.pop();
        return ret;
    }
    
    int peek() {
        if(stk2.empty()) {
            while(!stk1.empty()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        return stk2.top();
    }
    
    bool empty() {
        return stk1.empty() && stk2.empty();
    }
};

/*
    两个栈 stk1 stk2
        队列添加元素 => stk1.push
        取队头元素   => 将stk1元素push到stk2中，stk2栈顶元素就是队头元素
 */