#include <iostream>
#include <vector>
#include <memory>
#include <random>
#include <list>
using namespace std;

class A
{
public:
    int a, b;
};



int main()
{
    list<int> l;

    for(int i = 0; i < 10; ++i)
        l.push_back(i);

    for(auto i : l)
        cout << i << " ";

    cout << endl;
    return 0;
}