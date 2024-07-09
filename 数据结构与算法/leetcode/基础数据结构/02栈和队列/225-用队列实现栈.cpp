class MyStack {
public:
    queue<int> q;

    MyStack() {

    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int cnt = q.size();
        for(int i = 1; i < cnt; ++i) {
            q.push(q.front());
            q.pop();
        }
        int ret = q.front();
        q.pop();
        return ret;
    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
        return q.empty();
    }
};

/*
    向栈中压入元素 => 向队列尾push元素，此时栈顶在队列尾
    取出栈顶元素  => 不断将队列头元素push到队列尾，就能得到队列尾（栈顶元素）
*/