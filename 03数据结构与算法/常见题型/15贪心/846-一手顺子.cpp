class Solution {
public: // 0924华为线下一面手撕，正确。
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> h;
        for(int x : hand)
            h[x]++;
        
        while(!h.empty())
        {
            int x = h.begin()->first;
            for(int i = x; i < x + groupSize; ++i)
            {
                if(!h.count(i))
                    return false;
                else if(h[i] == 1)
                    h.erase(i);
                else 
                    h[i]--;
            }
        }

        return true;
    }
};