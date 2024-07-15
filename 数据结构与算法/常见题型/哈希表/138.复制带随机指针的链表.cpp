/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // 哈希表，建立原链表结点和新链表结点对应结点的映射关系
        unordered_map<Node *, Node *> h;
        for(auto p = head; p; p = p->next) {
            h[p] = new Node(p->val);
        }

        // 通过映射关系确定新链表结点的next和random
        for(auto p = head; p; p = p->next) {
            h[p]->next = h[p->next];
            h[p]->random = h[p->random];
        }

        return h[head];
    }
};