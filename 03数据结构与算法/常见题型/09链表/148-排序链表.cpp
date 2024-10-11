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
    ListNode* sortList(ListNode* head) { // 分治排序
        if(head == nullptr || head->next == nullptr)
            return head;
        
        auto slow = head, fast = head->next->next;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        auto l = head, r = slow->next;
        slow->next = nullptr;

        return MergeSort(sortList(l), sortList(r));
    }

    ListNode *MergeSort(ListNode *l, ListNode *r) // 递归法合并两个有序链表
    {
        if(l == nullptr) return r;
        if(r == nullptr) return l;

        if(l->val < r->val)
        {
            l->next = MergeSort(l->next, r);
            return l;
        }
        else
        {
            r->next = MergeSort(l, r->next);
            return r;
        }
    }
};