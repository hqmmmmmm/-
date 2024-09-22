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
    ListNode* reverseList(ListNode* head) {
        // 递归
        if(head == nullptr || head->next == nullptr) return head;
        auto newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;


        // 迭代
        // ListNode *pre = nullptr;
        // auto cur = head;;
        // while(cur)
        // {
        //     auto tmp = cur->next;
        //     cur->next = pre;
        //     pre = cur;
        //     cur = tmp;
        // }

        // return pre;
    }
};