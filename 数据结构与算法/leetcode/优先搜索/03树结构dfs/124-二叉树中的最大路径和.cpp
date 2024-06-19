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
    int ans = INT_MIN;

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }

    // 以root为根节点向下延展的路径的最大和
    int dfs(TreeNode *root) {
        if(root == nullptr) return 0;

        int l = max(0, dfs(root->left));
        int r = max(0, dfs(root->right));

        ans = max(ans, root->val + l + r);

        return root->val + max(l, r);
    }
};