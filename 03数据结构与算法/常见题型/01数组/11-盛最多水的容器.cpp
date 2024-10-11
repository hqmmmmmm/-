class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1, ans = 0;
        while(i < j)
        {
            ans = max(ans, min(height[i], height[j]) * (j - i));
            if(height[i] < height[j]) ++i;
            else --j;
        }

        // 一定要挪动左右边界更小的那个，因为如果挪动大的，得到的容器一定比当前小
        

        return ans;
    }
};