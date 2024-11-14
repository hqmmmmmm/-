class Solution {
public:
/*
对于l，是需要找到它的右侧有元素比它小，那么按照升序排列，这里就需要把最小值排序；就是从右向左遍历，记录当前最小值，和当前点比较，一旦大于，则说明需要移动
对于r，就是要找到左侧比它大的元素，则需要把大的元素移动过来；这里采用从左往右的遍历方式，记录最大值，和当前点比较，一旦小于，则说明需要移动
*/

    vector<int> subSort(vector<int>& array) {
        int l = -1, r = -1;
        int cur_min = INT_MAX, cur_max = INT_MIN;
        for(int i = array.size() - 1; i >= 0; --i) {
            if(array[i] > cur_min) 
                l = i;
            else  
                cur_min = min(cur_min, array[i]);
        }

        for(int i = 0; i < array.size(); ++i) {
            if(array[i] < cur_max) 
                r = i;
            else
                cur_max = max(cur_max, array[i]);
        }

        return {l, r};
    }
};