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
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        // 注意一下这一步可能递归会出现死循环，一定要控制好循环条件
        auto slow = head, fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *l = head, *r = slow->next;
        slow->next = nullptr;
        return mergeSort(sortList(l), sortList(r));
    }

    ListNode *mergeSort(ListNode *p, ListNode *q) {
        ListNode *dummy = new ListNode();
        auto pre = dummy;

        while(p && q)  {
            if(p->val > q->val) {
                pre->next = q;
                q = q->next;
            } else {
                pre->next = p;
                p = p->next;
            }
            pre = pre->next;
        }
        while(p) {
            pre->next = p;
            p = p->next;
            pre = pre->next;
        }
        while(q) {
            pre->next = q;
            q = q->next;
            pre = pre->next;
        }

        return dummy->next;
    }
};