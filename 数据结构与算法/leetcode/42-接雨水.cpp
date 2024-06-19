class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int res = 0;

        for(int i = 0; i < height.size(); ++i) {
            while(!st.empty() && height[st.top()] < height[i]) {
                auto tmp = height[st.top()]; 
                st.pop();

                if(st.empty()) break;

                int l = st.top(), r = i;
                res += (min(height[r], height[l]) - tmp) * (r - l - 1);
            }
            st.push(i);
        }

        return res;
    }
};