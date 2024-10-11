class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        stack<int> st;
        for(int i = 2 * n - 1; i >= 0; --i) // 将nums复制一份拼接在后面实现循环数组
        {
            while(!st.empty() && nums[i % n] >= st.top()) // 具体操作时不需要真的复制拼接，可以通过取模实现
                st.pop();
            
            if(i < n) res[i] = st.empty() ? -1 : st.top();

            st.push(nums[i % n]);
        }

        return res;
    }
};