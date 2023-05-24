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
    ListNode* swapPairs(ListNode* head) {
        ListNode* nhead = new ListNode(-1);
        nhead->next = head;
        
        ListNode* flag = nhead;
        while (flag->next != NULL and flag->next->next != NULL) {
            ListNode* nf = flag->next;
            ListNode* ns = flag->next->next;
            flag->next = ns;
            nf->next = ns->next;
            ns->next = nf;
            flag = flag->next->next;
        }
        return nhead->next;
    }
};
