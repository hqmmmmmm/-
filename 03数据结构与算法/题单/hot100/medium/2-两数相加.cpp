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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;

        auto dummy = new ListNode(0), p = dummy;
        int x1 = 0, x2 = 0, carry = 0;
        while(l1 || l2)
        {
            x1 = l1 ? l1->val : 0, x2 = l2 ? l2->val : 0;
            p->next = new ListNode((x1 + x2 + carry) % 10);

            carry = (x1 + x2 + carry) / 10;
            p = p->next;
            l1 = l1 ? l1->next : l1, l2 = l2 ? l2->next : l2;
        }

        if(carry) p->next = new ListNode(carry);

        return dummy->next;
    }
};