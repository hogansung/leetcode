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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* nhead = new ListNode(-1);
        nhead->next = head;
        
        ListNode* flag = nhead;
        while (flag->next != NULL) {
            if (flag->next->val == val) {
                flag->next = flag->next->next;
            } else {
                flag = flag->next;
            }
        }
        return nhead->next;
    }
};
