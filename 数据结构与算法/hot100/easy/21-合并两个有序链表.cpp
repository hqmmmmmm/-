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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 递归
        if(!list1) return list2;
        if(!list2) return list1;
        if(list1->val < list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else 
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }

        // 迭代
        // if(!list1) return list2;
        // if(!list2) return list1;
        // auto dummy = new ListNode(0), pre = dummy;
        // while(list1 && list2) 
        // {
        //     if(list1->val < list2->val) 
        //     {
        //         pre->next = list1;
        //         list1 = list1->next;
        //     }
        //     else 
        //     {
        //         pre->next = list2;
        //         list2 = list2->next;
        //     }
        //     pre = pre->next;
        // }

        // pre->next = list1 ? list1 : list2;
        // return dummy->next;
    }
};