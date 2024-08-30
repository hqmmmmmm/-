/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr) return nullptr;
        auto slow = head->next, fast = slow->next;
        // 快慢指针
        while(slow != fast && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        if(slow != fast) return nullptr;

        // 找出相交节点
        slow = head;
        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};