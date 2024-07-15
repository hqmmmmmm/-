class Solution {
public:
    int maxArea(vector<int>& height) {
        int i  = 0, j = height.size() - 1;
        int res = 0;
        while(i < j) {
            res = max(res, min(height[i], height[j]) * (j - i));
            if(height[i] > height[j]) --j;
            else ++i;
        }   

        return res;
    }
};

/*
    有点像贪心算法，一定是移动容器左右更矮的那端。
    如果移动更高的那端，那此后形成的容器高度一定小于等于当前，而且容器的底变得更短了，所以体积肯定更小。
*/