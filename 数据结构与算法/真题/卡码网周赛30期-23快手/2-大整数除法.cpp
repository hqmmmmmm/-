#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 模拟，像在拼积木

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    vector<int> v1, v2;
    for(auto c : str1) v1.push_back(c - '0');
    for(auto c : str2) v2.push_back(c - '0');

    vector<int> res;
    for(int i = 0; i < v2.size(); ++i)
    {
        int t = 0;
        for(int j = 0; j < v1.size(); ++j)
        {
            t += v2[i] * v1[j];
            if(i + j >= res.size())
            {
                res.push_back(t % 10); 
                t /= 10;
            }      
            else 
            {
                t += res[i + j];
                res[i + j] = t % 10;
                t /= 10;
            }
        }
        if(t) res.push_back(t);
    }

    for(int i = res.size() - 1; i >= 0; --i)
        cout << res[i];

    return 0;
}