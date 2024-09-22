/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // 返回{选，不选}
    pair<int, int> myrob(TreeNode *node) {
        if(node == nullptr) return {0, 0};
        auto l = myrob(node->left);
        auto r = myrob(node->right);

        int selected = l.second + r.second + node->val;
        int notselected = max(l.first, l.second) + max(r.first, r.second);
        return {selected, notselected};
    }

    int rob(TreeNode* root) {
        auto ans = myrob(root);
        return max(ans.first, ans.second);
    }
};

/*
    ！！！！这种做法超时了，优化一下，直接返回一个pair，不用递归两次分别计算偷和不偷了。！！！！！
    myrob(node, 0)代表当前节点不偷并且以node为根节点能盗取的最高金额，myrob(node, 1)同理
    根据当前节点是否偷分类
        偷    myrob(node->left, 0) + myrob(node->right, 0)
        不偷  myrob(node->left, 0), myrob(node->left, 1)  + myrob(node->right, 0), myrob(node->right, 1)

*/