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
    vector<int> preorder, inorder;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder, this->inorder = inorder;
        return build(0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode *build(int pl, int pr, int il, int ir)
    {
        if(pl > pr) return nullptr;
        TreeNode *root = new TreeNode(preorder[pl]);

        int pos = 0;
        for(int i = il; i <= ir; ++i)
        {
            if(inorder[i] == preorder[pl])
            {
                pos = i;
                break;
            }
        }

        root->left = build(pl + 1, pos - il + pl, il, pos - 1);
        root->right = build(pos - il + pl + 1, pr, pos + 1, ir);
        
        return root;
    }
};