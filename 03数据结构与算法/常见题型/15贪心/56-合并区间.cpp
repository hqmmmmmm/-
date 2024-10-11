class Solution {
public: // 看下一个区间与当前区间是否重叠，重叠的话就将r取max，不重叠的话将当前区间push到结果中，重复这个步骤。
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), [](vector<int> x,  vector<int> y){
            if(x[0] == y[0])
                return x[1] < y[1];
            return x[0] < y[0];
        });

        int l = intervals[0][0], r = intervals[0][1];
        for(int i = 1; i < intervals.size(); ++i)
        {
            if(intervals[i][0] > r)
            {
                res.push_back({l, r});
                l = intervals[i][0];
                r = intervals[i][1];
            }
            else 
                r = max(r, intervals[i][1]);
        }

        res.push_back({l, r});
        return res;
    }
};