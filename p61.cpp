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
    int calDep(ListNode* head) {
        if (head == 0) {
            return 0;
        } else {
            return calDep(head->next) + 1;
        }
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        int dep = calDep(head);
        
        if (dep == 0 or k % dep == 0) {
            return head;
        } else {
            k %= dep;
            ListNode* nhead = head;
            for (int i = 0; i < dep-k-1; i++) {
                nhead = nhead->next;
            }

            ListNode* flag = nhead->next;
            nhead->next = NULL;
            nhead = flag;
            while (flag->next != NULL) {
                flag = flag->next;
            }
            flag->next = head;
            return nhead;
        }
    }
};
