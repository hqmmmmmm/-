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
        auto slow = head, fast = head;
        // 先获取链表中间节点
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 翻转后半部分
        ListNode *pre = nullptr, *cur = slow;
        while(cur) {
            auto tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }

        // 判断以head和pre开头的链表是否相同
        // 这两个链表的尾部可能有点模糊，只要让两个链表都不为空作为循环的条件即可（其实pre就够了，好好想想）
        while(head && pre) {
            if(head->val != pre->val) {
                return false;
            }
            head = head->next;
            pre = pre->next;
        }
        return true;
    }
};