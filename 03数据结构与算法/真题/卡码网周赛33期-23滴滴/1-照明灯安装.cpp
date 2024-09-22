#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k; cin >> n >> k;
    vector<int> x(n);
    for(int i = 0; i < n; ++i) cin >> x[i];

    // 等价于：从数组x中取出k个数，最小距离最大可以是多少？
    /*
        f[i]表示从数组x中前i个数字中取j个的最小距离的最大值。
            第i个数字不取 f[i][j] = f[i - 1][j] 
            第i个数字取   f[i][j] = max{ min(f[i - 1][j - 1], x[j] - x[j - 1]), min(f[i - 2][j - 1], x[j] - x[j - 2]) }

        f[0][]
    */

    // 根据状态转移方程确定需要初始化哪些初始状态。
    vector<vector<int>> f(n + 1, vector<int>(k + 1));
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= k ; ++k)
        {
            f[i][j] = f[i - 1][j];
            for(int t = 1; t < i; ++t)
                f[i][j] = max(f[i][j], min(f[i - t][j - 1], x[i - 1] - x[i - 1 - t]));
        }
    }

    cout << f[n][k] << endl;

    return 0;
}