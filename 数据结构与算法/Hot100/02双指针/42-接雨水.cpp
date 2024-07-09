class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int res = 0;

        for(int i = 0; i < height.size(); ++i) { 
            // 注意因为push的是下标，所以不要拿小标去比大小了，很容易出错
            while(!st.empty() && height[st.top()] < height[i]) {
                int tmp = height[st.top()];
                st.pop();

                if(!st.empty()) {
                    res += (min(height[i], height[st.top()]) - tmp) * (i - st.top() - 1);
                }
            } 
            st.push(i);  // 注意push的一定要是下标，因为我们需要计算底的大小嘛
        }

        return res;
    }
};

/*
    这题最主要就是要push下标，
    然后注意栈中存的是下标，拿出栈中元素比较或者其它操作时，注意拿的是下标

*/