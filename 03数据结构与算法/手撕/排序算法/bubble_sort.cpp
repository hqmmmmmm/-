#include <vector>
using namespace std;


void bubble_sort(vector<int> &arr)
{
    int n = arr.size();
    for(int i = 0; i < n - 1; ++i)
    {
        for(int j = 0; j < n - i - 1; ++j)
        {
            if(arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

// 添加一个flag优化
void bubble_sort_flag(vector<int> &arr)
{
    int n = arr.size();
    for(int i = 0; i < n - 1; ++i)
    {
        bool flag = false;
        for(int j = 0; j < n - i - 1; ++j)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = true;
            }
        }
        if(!flag) break;
    }
}