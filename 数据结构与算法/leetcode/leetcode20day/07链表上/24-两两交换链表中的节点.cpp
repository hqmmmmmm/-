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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        // 因为需要知道前驱节点，所以设置一个虚拟头结点
        auto dummy = new ListNode(0, head);
        auto a = dummy;

        while(a->next && a->next->next) {
            auto b = a->next, c = b->next;

            a->next = c;
            // 其实只要这两步之间的顺序不要搞反就行了，挺简单的
            b->next = c->next;  
            c->next = b;

            a = b;
        }
        
        return dummy->next;
    }
};