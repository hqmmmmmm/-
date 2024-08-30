#include <iostream>
using namespace std;

const int N = 100010;
int a[N];

int main()
{
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> a[i];
    while(q--)
    {
        int x;
        cin >> x;
        int l = 0, r = n - 1;
        while(l < r)  // 模板1
        {
            int mid = l + r >> 1;
            if(a[mid] >= x) // 模板1尽量往左找，会找到左边界
                r = mid;
            else 
                l = mid + 1;
        }
        if(a[l] != x)  // 如果不存在这个数，就输出-1-1后进入下一个询问
        {
            cout << "-1 -1" << endl;
            continue;
        }
        else cout << l << " ";
        
        l = 0, r = n - 1;
        while(l < r)  // 模板2
        {
            int mid = l + r + 1 >> 1;  // 模板2的mid需要加1
            if(a[mid] <= x)  // 模板2尽量往右找，会找到右边界
                l = mid;
            else
                r = mid - 1;
        }
        cout << l << endl;
    }
    
    return 0;
}