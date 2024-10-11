/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        // 使用已经建立好的链表关系 空间复杂度O(1)
        Node *cur = root;
        while(cur)
        {
            auto head = new Node(), tail = head;
            for(auto p = cur; p; p = p->next)
            {
                if(p->left)  tail = tail->next = p->left;
                if(p->right) tail = tail->next = p->right;
            }

            cur = head->next;
        }

        return root;



        // 层次遍历 空间复杂度O(n)  用了队列
        // queue<Node *> q;
        // if(root) q.push(root);
        // while(!q.empty())
        // {
        //     int cnt = q.size();
        //     for(int i = 1; i <= cnt; ++i)
        //     {
        //         auto t = q.front();
        //         q.pop();

        //         t->next = i < cnt ? q.front() : nullptr;

        //         if(t->left)  q.push(t->left);
        //         if(t->right) q.push(t->right);
        //     }
        // }

        // return root;
    }
};