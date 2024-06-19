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
    ListNode *re(ListNode *head, int k) {
        ListNode *pre = nullptr, *cur = head;
        for(int i = 0; i < k; ++i) {
            auto tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }

        return pre;
    }


    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt = 0;
        for(auto p = head; p; p = p->next) {
            ++cnt;
        }
        cnt /= k;

        auto dummy = new ListNode(0, head);
        ListNode *pre = dummy, *cur = pre->next;
        while(cnt--) {
            auto tmp = cur; for(int i = 0; i < k; ++i) tmp = tmp->next;

            pre->next = re(cur, k);
            pre = cur;
            cur = tmp;
        }
        pre->next = cur;

        return dummy->next;
    }
};