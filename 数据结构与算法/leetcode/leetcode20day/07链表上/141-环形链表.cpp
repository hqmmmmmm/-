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
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr) return false;
        auto slow = head->next, fast =  slow->next;
        while(slow != fast && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        if(fast == nullptr ||fast->next == nullptr) return false;
        return true;
    }
};