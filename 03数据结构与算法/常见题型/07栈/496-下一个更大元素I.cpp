class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // 记录nums2中数字与下一个更大元素的对应关系
        unordered_map<int, int> h;
        
        // 先求出nums2中每一个数字的下一个更大元素
        stack<int> st;
        for(int i = nums2.size() - 1; i >= 0; --i)
        {
            while(!st.empty() && st.top() <= nums2[i]) 
                st.pop();

            if(st.empty()) 
                h[nums2[i]] = -1;
            else 
                h[nums2[i]] = st.top();

            st.push(nums2[i]);
        }

        // 将对应的下一个更大元素放入ans中
        vector<int> ans(nums1.size());
        for(int i = 0; i < nums1.size(); ++i)
            ans[i] = h[nums1[i]];

        return ans;
    }
};