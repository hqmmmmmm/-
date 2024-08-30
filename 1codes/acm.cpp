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


int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    int l, r;
    for(int i = 0; i < m; ++i)
    {
        cin >> l >> r;
        for(int j = l - 1; j <= r - 1; ++j) 
        {
            if(b[j] >= a[j])
            {
                cout << i << endl;
                return 0;
            }
            ++b[j];
        }
    }

    cout << m << endl;

    return 0;
}