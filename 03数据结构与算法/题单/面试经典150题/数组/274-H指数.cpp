class Solution {
public:
    int hIndex(vector<int>& citations) { 
        // 计数排序 O(n)
        // 统计所有数字出现的次数，大于n的直接当成n，因为H指数不可能大于n。
        int n = citations.size();
        vector<int> count(n + 1);
        for(int x : citations)
        {
            if(x >= n)
                count[n]++;
            else
                count[x]++;
        }

        // 从最大的数开始遍历，第一个满足条件的就是H指数.
        int sum = 0;
        for(int i = n; i >= 0; --i)
        {
            sum += count[i];
            if(sum >= i)
                return i;
        }

        return 0;




        // 排序+模拟  O(nlogn)
        // sort(citations.begin(), citations.end(), std::greater<int>());

        // for(int i = 0; i < citations.size(); ++i)
        // {
        //     if(citations[i] < i + 1)
        //         return i;
        // }

        // return citations.size();
    }
};