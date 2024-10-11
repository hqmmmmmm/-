class MinStack {
public:
    stack<long long> st;
    int curmin;

    MinStack() {
    }
    
    void push(int val) {
        if(st.empty()) 
            curmin = val;
        st.push((long long)val - curmin);
        curmin = min(curmin, val);
    }
    
    void pop() {
        if(st.top() < 0) 
            curmin -= st.top();
        st.pop();
    }
    
    int top() {
        if(st.top() < 0)
            return curmin;
        return curmin + st.top();
    }
    
    int getMin() {
        return curmin;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */