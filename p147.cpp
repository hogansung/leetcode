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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* nhead = new ListNode(-1);
        nhead->next = head;
        
        ListNode* ret = new ListNode(-1);
        ListNode* ret_flag = ret;
        while (nhead->next != NULL) {
            ListNode* flag = nhead;
            long long mmin = LLONG_MAX;
            ListNode* target;
            while (flag->next != NULL) {
                if (flag->next->val < mmin) {
                    mmin = flag->next->val;
                    target = flag;
                }
                flag = flag->next;
            }
            ret_flag->next = target->next;
            target->next = target->next->next;
            ret_flag = ret_flag->next;
        }
        return ret->next;
    }
};
