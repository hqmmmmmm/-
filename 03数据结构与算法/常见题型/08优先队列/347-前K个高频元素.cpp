class Solution {
public: // 时间复杂度 O(nlogk)
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> h;
    for (int num : nums)
      h[num]++;
    
    using PII = pair<int, int>;
    auto compare = [](PII p1, PII p2) { return p1.second > p2.second; };
    priority_queue<PII, vector<PII>, decltype(compare)> heap; // 大根堆用小于号，小根堆用大于号

    for (auto &[key, value] : h) {
      if (heap.size() < k)
        heap.push({key, value});
      else {
        if (heap.top().second < value) {
          heap.pop();
          heap.push({key, value});
        }
      }
    }

    vector<int> res;
    while (!heap.empty()) {
      res.push_back(heap.top().first);
      heap.pop();
    }
    return res;
  }
};