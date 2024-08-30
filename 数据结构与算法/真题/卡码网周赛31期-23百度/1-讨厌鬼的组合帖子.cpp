#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <queue>
#include <array>
using namespace std;

using ll = long long;
// 统计所有差值，差值肯定要么全选正的要么全选负的，如果有正有负结果肯定更小。
int main()
{
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];

    ll pos = 0, neg = 0;
    for(int i = 0; i < n; ++i) 
    {
        int d = a[i] - b[i];
        if(d < 0) neg += abs(d);
        else pos += abs(d);
    }

    cout << max(pos, neg) << endl;

    return 0;
}