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
    bool isPalindrome(ListNode* head) {
        // 获取链表中间结点
        auto slow = head, fast= head;
        while(fast && fast->next) 
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse slow
        ListNode *pre = nullptr, *cur = slow;
        while(cur)
        {
            auto tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }

        // compare head and pre
        // 这两个链表的尾部可能有点模糊，只要让两个链表都不为空作为循环的条件即可（其实pre就够了，好好想想）
        while(pre)
        {
            if(head->val != pre->val)
                return false;
            head = head->next, pre = pre->next;
        }

        return true;
    }
};