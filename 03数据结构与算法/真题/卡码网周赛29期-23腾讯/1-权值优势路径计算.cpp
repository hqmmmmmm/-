#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <queue>
using namespace std;

class TreeNode
{
public:
    TreeNode *left, *right;
    int val;
public:
    TreeNode(int v): left(nullptr), right(nullptr), val(v) {}
};

// 因为这题-1下面不会再有-1，所以不是一个完全二叉树，不能使用数组构建
// 通过层序遍历序列构建二叉树
TreeNode *build(vector<int> &nums)
{
    if(nums.size() == 0 || nums[0] == -1) return nullptr;

    queue<TreeNode *> q;
    auto root = new TreeNode{nums[0]};
    q.push(root);
    int index = 1;

    while(!q.empty() && index < nums.size())
    {
        auto node = q.front();
        q.pop();

        if(index < nums.size() && nums[index] != -1)
        {
            node->left = new TreeNode{nums[index]};
            q.push(node->left);
        }
        ++index;

        if(index < nums.size() && nums[index] != -1)
        {
            node->right = new TreeNode{nums[index]};
            q.push(node->right);
        }
        ++index;
    }

    return root;
}

int res;
// 编程中一定要注意各语句之间的逻辑顺序关系，仔细想想
void dfs(TreeNode *root, int cnt_0, int cnt_1)
{
    if(root == nullptr) return ;

    // 先统计cnt再判断是否为叶子节点！！！否则叶子节点不会被统计到
    if(root->val == 0) ++cnt_0;
    if(root->val == 1) ++cnt_1;

    if(root->left == nullptr && root->right == nullptr)
    {
        if(cnt_0 == cnt_1 - 1) ++res;
        return ;
    }

    dfs(root->left, cnt_0, cnt_1);
    dfs(root->right, cnt_0, cnt_1);
}

int main()
{
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) cin >> nums[i];

    auto root = build(nums);
    dfs(root, 0, 0);
    cout << res << endl;

    return 0;
}