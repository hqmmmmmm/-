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
    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return 0;

        int res = dfs(root, targetSum);
        res += pathSum(root->left, targetSum);
        res += pathSum(root->right, targetSum);

        return res;
    }

    int dfs(TreeNode *root, int targetSum) {
        if(root == nullptr) return 0;

        int ret = 0;
        if(root->val == targetSum) ret += 1;
        ret += dfs(root->left, targetSum - root->val);
        ret += dfs(root->right,  targetSum - root->val);

        return ret;
    }
};