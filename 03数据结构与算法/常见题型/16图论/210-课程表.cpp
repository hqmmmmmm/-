class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> d(numCourses); // 入度
        vector<vector<int>> ne(numCourses);    // 邻接表
        vector<int> res;

        for(int i = 0; i < prerequisites.size(); ++i)
        {
            d[prerequisites[i][0]]++;
            ne[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        queue<int> q;
        for(int i = 0; i < numCourses; ++i)
            if(d[i] == 0)
                q.push(i);

        while(!q.empty())
        {
            auto t = q.front();
            q.pop();
            res.push_back(t);

            for(int i = 0; i < ne[t].size(); ++i)
                if(--d[ne[t][i]] == 0)
                    q.push(ne[t][i]);
        }

        if(res.size() != numCourses) return {};
        return res;
    }
};