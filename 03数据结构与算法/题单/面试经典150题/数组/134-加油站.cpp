class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // 贪心 虽然是双重for，但是只会走一圈，所以O(n)
        // 主要思想就是如果x走不到y，那下次直接从y开始走，因为x,x+1,...y-1都走不到y
        int n = gas.size();
        for(int i = 0; i < n; ++i)
        {
            int oil = 0;
            for(int j = i; ; j = (j + 1) % n)
            {
                oil += (gas[j] - cost[j]);
                if(oil < 0)
                {
                    if(i > j) return -1; // 这时候不能再i=j了，因为这个j我们在i中已经遍历过了
                    i = j;
                    break;
                }
                else 
                {
                    if((j + 1) % n == i) // 走完一圈
                        return i;
                }
            }
        }

        return -1;
    }
};
    }
};