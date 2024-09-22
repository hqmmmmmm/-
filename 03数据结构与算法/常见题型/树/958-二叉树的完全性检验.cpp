/*
 * @Descripttion: your project
 * @version: 1.0
 * @Author: yuy77
 * @Date: 2024-07-15 22:32:51
 * @LastEditors: yuy77
 * @LastEditTime: 2024-07-15 22:32:57
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  // 使用层序遍历，只要判断遍历一个非空节点之前有没有遍历过一个空节点
  bool isCompleteTree(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    bool flag = false;
    while (!q.empty()) {
      auto node = q.front();
      q.pop();
      if (node == nullptr)
        flag = true;
      else {
        if (flag)
          return false;
        q.push(node->left);
        q.push(node->right);
      }
    }

    return true;
  }
};