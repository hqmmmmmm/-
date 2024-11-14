class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> res(n);

        // 单调栈+逆序遍历，单调栈中存放下标，不需要存放数
        for(int i = res.size() - 1; i >= 0; --i) {
            while(!st.empty() && temperatures[st.top()] <= temperatures[i]) 
                st.pop();

            if(st.empty()) 
                res[i] = 0;
            else 
                res[i] = st.top() - i;

            st.push(i);
        }
        
        return res;
    }
};