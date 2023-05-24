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
    ListNode* partition(ListNode* head, int x) {
        ListNode* shead = new ListNode(-1);
        ListNode* lhead = new ListNode(-1);
        ListNode* sflag = shead;
        ListNode* lflag = lhead;
        while (head) {
            if (head->val < x) {
                sflag->next = head;
                sflag = sflag->next;
            } else {
                lflag->next = head;
                lflag = lflag->next;
            }
            head = head->next;
        }
        sflag->next = lhead->next;
        lflag->next = NULL;
        return shead->next;
    }
};
