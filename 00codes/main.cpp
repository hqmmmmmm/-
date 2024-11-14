// 2024/5/25/0025.

#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <shared_mutex>
#include <thread>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;


int main() {
  vector<int> arr = {1, 2, 3};
  cout << arr.size() << " " << arr.capacity() << endl;
  arr.push_back(1);
  cout << arr.size() << " " << arr.capacity() << endl;

  arr.resize(15);
  cout << arr.size() << " " << arr.capacity() << endl;


  return 0;
}