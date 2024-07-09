#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void input(string &str, vector<int> &nums) {
    for(int i = 0; i < str.size(); ++i) {
        if(!isdigit(str[i])) continue;
        int start = i;
        while(i < str.size() && isdigit(str[i])) ++i;
        nums.push_back(stoi(str.substr(start, i - start)));
    }
}

int main() {
    vector<int> nums;
    string str; cin >> str;
    input(str, nums);

    int n = nums.size();
    vector<int> res(n, 1);


    // 用两次单调栈
    stack<int> st;
    for(int i = 0; i < n; ++i) {
        res[i] += st.size();
        while(!st.empty() && st.top() <= nums[i]) st.pop();
        st.push(nums[i]);
    }

    while(!st.empty()) st.pop();
    reverse(nums.begin(), nums.end());
    for(int i = 0; i < n; ++i) {
        res[n - 1 - i] += st.size();
        while(!st.empty() && st.top() <= nums[i]) st.pop();
        st.push(nums[i]);
    }

    cout << "[";
    for(int i = 0; i < n - 1; ++i) cout << res[i] << ",";
    cout << res[n - 1] << "]\n";

    return 0;
}