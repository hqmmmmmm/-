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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeK(lists, 0, lists.size() - 1);
    }

    ListNode *mergeK(vector<ListNode *> lists, int l, int r) {
        if(l > r) return nullptr;
        if(l == r) return lists[l];
        int mid = (l + r) >> 1;

        ListNode *L = mergeK(lists, l, mid);
        ListNode *R = mergeK(lists, mid + 1, r);;
        return merge(L, R);
    }

    ListNode *merge(ListNode *l, ListNode *r) {
        ListNode *dummy = new ListNode();
        ListNode *cur = dummy;
        while(l && r) {
            if(l->val > r->val) {
                cur->next = r;
                r = r->next;
            } else {
                cur->next = l;
                l = l->next;
            }
            cur = cur->next;
        }
        if(l) cur->next = l;
        if(r) cur->next = r;

        return dummy->next;
    }
};