#include <iostream>
#include <climits>
using namespace std;

// 扩展欧几里得算法
int exgcd(int a, int b, int &x, int &y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int gcd = exgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}

int main()
{
    int a, b; cin >> a >> b;
    int x, y;
    exgcd(a, b, x, y);

    x = (x % b + b) % b;  // 确保是最小正整数解
    /*
        ax + by = 1;
            => a(x + kb) + b(y - ka) = 1;
        所以x加减b对等式都能成立。
    */
    cout << x << endl;

    return 0;
}