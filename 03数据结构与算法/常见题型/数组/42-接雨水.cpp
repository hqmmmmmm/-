class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int res = 0;

        for(int i = 0; i < height.size(); ++i)
        {
            // 注意因为push的是下标，所以不要拿小标去比大小了，很容易出错
            while(!st.empty() && height[st.top()] < height[i]) 
            {
                int t = st.top();
                st.pop();

                if(st.empty()) break;

                int l = st.top(), r = i;
                res += (min(height[l], height[r]) - height[t]) * (r - l - 1);
            }
            st.push(i);
        }

        return res;
    }
};
/*
    这题最主要就是要push下标，
    然后注意栈中存的是下标，拿出栈中元素比较或者其它操作时，注意拿的是下标
*/