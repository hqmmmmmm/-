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
    list<int> l = {1, 2, 3, 4, 5, 6, 7, 8};

    for(auto it = l.begin(); it != l.end(); )
    {
        it = l.erase(it);
    }

    cout << l.size();

    cout << endl;
    return 0;
}