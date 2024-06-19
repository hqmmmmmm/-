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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 要删除倒数第n个节点，要获取到倒数第n+1个节点
        // 如果要删除的是第一个节点，救获取不到倒数第n+1个节点，所以增加一个虚拟头结点
        auto dummy = new ListNode(0, head);
        auto slow = dummy, fast = dummy;
        for(int i = 0; i < n + 1; ++i) fast = fast->next;
        while(fast) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        return dummy->next;
    }   
};