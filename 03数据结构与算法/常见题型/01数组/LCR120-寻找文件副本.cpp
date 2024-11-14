class Solution {
public:
    int findRepeatDocument(vector<int>& documents) {
        // 将元素放在对应下标上，不用哈希表，空间复杂度为O(1)
        for(int i = 0; i < documents.size(); ) {
            if(documents[i] == i) {
                ++i;
                continue;
            }

            if(documents[documents[i]] == documents[i])
                return documents[i];
            else    
                swap(documents[i], documents[documents[i]]);
        }

        return -1;
    }
};