/*
 * @Descripttion: your project
 * @version: 1.0
 * @Author: yuy77
 * @Date: 2024-07-14 22:28:24
 * @LastEditors: yuy77
 * @LastEditTime: 2024-07-14 22:28:46
 */
class RandomizedSet {
private:
  vector<int> nums;
  unordered_map<int, int> h;

public:
  RandomizedSet() { srand(time(NULL)); }

  bool insert(int val) {
    if (h.count(val))
      return false;
    nums.push_back(val);
    h[val] = nums.size() - 1;
    return true;
  }

  bool remove(int val) {
    if (!h.count(val))
      return false;
    // vector O(1)删除元素，不过元素的顺序得不到保证
    int index = h[val];
    int last = nums.back();

    nums[index] = last;
    nums.pop_back();
    // 不要忘记修改哈希表的内容
    h[last] = index;
    h.erase(val);

    return true;
  }

  int getRandom() {
    int index = rand() % nums.size();
    return nums[index];
  }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */