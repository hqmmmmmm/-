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
        // 快慢指针 O(n), O(1)
        if(head == nullptr || head->next == nullptr) return false;
        ListNode *slow = head->next, *fast = slow->next;
        while(slow != fast)
        {
            if(fast == nullptr || fast->next == nullptr) return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;

        // 哈希表 O(n), O(n)
        // unordered_set<ListNode *> st;
        // while(head)
        // {
        //     if(st.count(head)) return true;
        //     st.insert(head);
        //     head = head->next;
        // }

        // return false;
    }
};