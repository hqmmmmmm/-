class MinStack {
public:
    stack<int> st;
    stack<int> st_min;  // 使用辅助栈；
    MinStack() {

    }
    
    void push(int val) {
        st.push(val);
        if(st_min.empty() || st_min.top() >= val) st_min.push(val);
    }
    
    void pop() {
        if(st.top() == st_min.top()) st_min.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return st_min.top();
    }
};

/*
    另一种空间复杂度O(1)的做法
        一个curmin记录当前栈中最小值；
        栈st中记录当前元素与最小值的差值sub
 */