#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <iomanip>
using namespace std;

using PDD = pair<double, double>;

double dis(PDD p1, PDD p2)
{
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

int main()
{
    int n; cin >> n;
    vector<PDD> nodes(n);
    for(int i = 0; i < n; ++i) cin >> nodes[i].first >> nodes[i].second;
    double d; cin >> d;

    double cur_len = 0;
    PDD cur_node{nodes[0]};
    cout << fixed << setprecision(5);
    cout << cur_node.first << ", " << cur_node.second << endl;

    for(int i = 0; i < nodes.size() - 1; )
    {
        auto x = dis(cur_node, nodes[i + 1]);
        if(cur_len + x < d) 
        {
            cur_node = nodes[++i];
            cur_len += x;
        }
        else  
        {
            cur_node.first  += ((d - cur_len) / x) * (nodes[i + 1].first - cur_node.first);
            cur_node.second += ((d - cur_len) / x) * (nodes[i + 1].second - cur_node.second);
            cur_len = 0;
            cout << cur_node.first << ", " << cur_node.second << endl;
        }
    }

    return 0;
}