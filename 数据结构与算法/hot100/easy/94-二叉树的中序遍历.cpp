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
    vector<int> inorderTraversal(TreeNode* root) {
        // 迭代法
        // stack<TreeNode *> st;
        // vector<int> res;
        // while(!st.empty() || root != nullptr)
        // {
        //     while(root)
        //     {
        //         st.push(root);
        //         root = root->left;
        //     }
            
        //     root = st.top();
        //     st.pop();

        //     res.push_back(root->val);
        //     root = root->right;
        // }

        // return res;

        // 递归法
        vector<int> res;
        re(root, res);
        return res;
    }

    void re(TreeNode *root, vector<int> &res)
    {   
        if(root == nullptr) return;
        re(root->left, res);
        res.push_back(root->val);
        re(root->right, res);
    }
};