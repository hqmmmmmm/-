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
    int res = 0;

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return res;
    }

    // 计算以root为左/右节点能提供的路径长度
    int dfs(TreeNode *root)
    {
        if(root == nullptr) return 0;
        int l = dfs(root->left), r = dfs(root->right);
        res = max(res, l + r);
        return max(l, r) + 1;
    }
};