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
        auto node = new TreeNode(preorder[pl]);

        // 找到根节点在中序遍历序列中的下标
        int root_pos = il;
        while(inorder[root_pos] != preorder[pl]) root_pos++;
        // 左子树和右子树的长度
        int left_len = root_pos - il, right_len = ir - root_pos;
        // 构造左子树和右子树
        node->left  = build(pl + 1, pl + left_len, il, root_pos - 1);
        node->right = build(pl + left_len + 1, pr, root_pos + 1, ir);

        return node;
    }
};