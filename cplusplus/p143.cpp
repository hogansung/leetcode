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
        if (head == NULL) {
            return 0;
        } else {
            return calDep(head->next) + 1;
        }
    }
    
    ListNode* reverseList(ListNode* head, ListNode* pre) {
        if (head->next == NULL) {
            head->next = pre;
            return head;
        } else {
            ListNode* ret = reverseList(head->next, head);
            head->next = pre;
            return ret;
        }
    }
    
    void reorderList(ListNode* head) {
        int dep = calDep(head);
        if (dep <= 1) {
            // do nothing
        } else {
            ListNode* flag = head;
            for (int i = 0; i < (dep-1)/2; i++) {
                flag = flag->next;
            }
            
            ListNode* tail = reverseList(flag->next, NULL);
            flag->next = NULL;
            
            flag = head;
            while (tail != NULL) {
                ListNode* h_next = flag->next;
                flag->next = tail;
                flag = h_next;
                ListNode* t_next = tail->next;
                tail->next = flag;
                tail = t_next;
            }
        }
    }
};
