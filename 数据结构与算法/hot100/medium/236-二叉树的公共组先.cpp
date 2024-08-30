/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q || root == nullptr) return root;
        auto l = lowestCommonAncestor(root->left, p);
        auto r = lowestCommonAncestor(root->right, q);
        if(l && r) return root;
        if(l) return l;
        if(r) return r;
        return nullptr
    }
};