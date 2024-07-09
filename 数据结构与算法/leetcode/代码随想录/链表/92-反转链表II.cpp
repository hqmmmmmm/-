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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        auto dummy = new ListNode(0, head), pre = dummy;
        for(int i = 0; i < left - 1; ++i) pre = pre->next;

        auto left_node = pre->next; /// 记录left那个节点，最后需要用到
        auto cur = left_node->next;  // 当前需要头插的节点（肯定是从第二个节点开始头插嘛，第一个可以看作已经插入了）
        for(int i = 0; i < right - left; ++i) {
            auto tmp = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = tmp;
        }
        
        left_node->next = cur;
        return dummy->next;
    }
};

/*
    这种穿针引线的时候，你记录了什么，就可以修改什么。
    比如你auto tmp = cur->next; 那么cur的next就是可以修改的。
*/