#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> p;

int FIND(int x)
{
    if(p[x] != x)
        p[x] = FIND(p[x]);
    return p[x];
}

void UNION(int x, int y)
{
    int fx = FIND(x), fy = FIND(y);
    if(fx != fy)
        p[fx] = fy;
}

int main()
{
    cin >> n >> m;
    p.resize(n + 1);
    for(int i = 1; i <= n; ++i) p[i] = i;
    while(m--)
    {
        char c; int a, b; cin >> c >> a >> b;
        if(c == 'M')
        {
            UNION(a, b);
        }
        else 
        {
            if(FIND(a) == FIND(b))
                cout << "Yes" << endl;
            else 
                cout << "No" << endl;
        }
    }
    
    return 0;
}