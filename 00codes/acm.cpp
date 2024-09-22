#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <queue>
#include <array>
#include <map>
using namespace std;
const int INF = 0x3f3f3f3f;

int main()
{
    map<int, int> mp;
    int n, m; 
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) 
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    cin >> m;
    vector<int> b(m);
    for(int i = 0; i < m; ++i) cin >> b[i];

    
    for(int i = 0; i < min(n, m); ++i)
    {
        if(a[i] == b[i])
            mp[a[i]]--;
    }


    stringstream ss;
    for(auto &[k, v] : mp)
    {
        if(v) ss << k;
    }
    string str = ss.str();
    reverse(str.begin(), str.end());
    cout << str << endl;
      
    return 0;
}