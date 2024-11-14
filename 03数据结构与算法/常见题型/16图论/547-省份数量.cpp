class Solution {
public:
    vector<int> p;

    int FIND(int x) {
        if(p[x] != x)
            p[x] = FIND(p[x]);
        return p[x];
    }

    void UNION(int x, int y) {
        if(FIND(x) != FIND(y)) 
            p[FIND(x)] = FIND(y);
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        p.resize(n);
        for(int i = 0; i < n; ++i) p[i] = i;

        for(int i = 0; i < isConnected.size(); ++i) {
            for(int j = 0; j < isConnected[0].size(); ++j) {
                if(isConnected[i][j] == 1)
                    UNION(i, j);
            }
        }

        unordered_set<int> st;
        for(int i = 0; i < n; ++i)
            st.insert(FIND(i));
        return st.size();
    }
};