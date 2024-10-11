/**
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
    vector<int> inorder, postorder;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        this->inorder = inorder, this->postorder = postorder;
        return build(0, inorder.size() - 1, 0, postorder.size() - 1);
    }

    TreeNode *build(int il, int ir, int pl, int pr)
    {
        if(il > ir) return nullptr;
        auto node = new TreeNode(postorder[pr]);

        // 找到根节点在中序遍历序列中的下标
        int root_pos = il;
        while(inorder[root_pos] != postorder[pr]) root_pos++;
        // 左子树和右子树的长度
        int left_len = root_pos - il, right_len = ir - root_pos;
        // 构造左子树和右子树
        node->left  = build(il, root_pos - 1, pl, pl + left_len -1);
        node->right = build(root_pos + 1, ir, pl + left_len, pr - 1);

        return node;
    }
};