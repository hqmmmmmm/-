class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap;
        for(int stone : stones) heap.push(stone);

        while(heap.size() >= 2) {
            int x = heap.top(); heap.pop();
            int y = heap.top(); heap.pop();
            heap.push(x - y);
        }

        if(heap.empty()) return 0;
        return heap.top();
    }
};