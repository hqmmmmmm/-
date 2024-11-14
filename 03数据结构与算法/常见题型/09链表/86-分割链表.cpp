/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *l = new ListNode(-1), *r = new ListNode(-1);
        auto p = l, q = r;

        for(auto it = head; it; it = it->next) {
            if(it->val < x)
                p = p->next = it;
            else
                q = q->next = it;
        }

        p->next = r->next;
        q->next = nullptr;
        return l->next;
    }
};