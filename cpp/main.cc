#include <iostream>
#include <vector>
#include <memory>
#include <random>
#include <list>
#include <string>
using namespace std;

class A
{
public:
    int a, b;
};

void test_insert()
{
    vector<int> nums;
    nums.insert(nums.begin() + 2, 2);

    // for(auto num : nums) cout << num << " ";
    // cout << endl;
}


void test_resize()
{
    vector<int> v = {1, 2, 3};
    cout << v.size() << endl;
    v.resize(5);
    cout << v.size() << endl;
}

int main()
{
    //test_insert();
    // test_resize();
    cout << sizeof(string) << endl;

    return 0;
}