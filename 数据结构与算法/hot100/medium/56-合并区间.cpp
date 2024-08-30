class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> p1, vector<int> p2) {
            if(p1[0] == p2[0]) return p1[1] < p2[1];
            return p1[0] < p2[0];
        });

        vector<vector<int>> res;
        int l = intervals[0][0], r = intervals[0][1];
        for(int i = 1; i < intervals.size(); ++i)
        {
            if(intervals[i][0] > r)
            {
                res.push_back({l, r});
                l = intervals[i][0], r = intervals[i][1];
            }
            else 
                r = max(r, intervals[i][1]);
        }

        res.push_back({l, r});
        return res;
    }
};