class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> d(numCourses); // 记录入度；
        vector<vector<int>> ne(numCourses, vector<int>()); // 邻接表

        for(int i = 0; i < prerequisites.size(); ++i)
        {
            ne[prerequisites[i][1]].push_back(prerequisites[i][0]);
            d[prerequisites[i][0]]++;
        }

        queue<int> q;
        for(int i = 0; i < d.size(); ++i) 
        {
            if(d[i] == 0)
                q.push(i);
        }

        int res = 0;
        while(!q.empty())
        {
            auto t = q.front();
            q.pop();
            res++;

            for(int i = 0; i < ne[t].size(); ++i)
                if(--d[ne[t][i]] == 0)
                    q.push(ne[t][i]);
        }

        return res == numCourses;
    }
};