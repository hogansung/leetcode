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
    ListNode* sortList(ListNode* head) {
        ListNode* l_head = new ListNode(-1);
        ListNode* r_head = new ListNode(-1);
        ListNode* l_flag = l_head;
        ListNode* r_flag = r_head;

        while (head != NULL) {
            l_flag->next = head;
            l_flag = l_flag->next;
            head = head->next;

            if (head != NULL) {
                r_flag->next = head;
                r_flag = r_flag->next;
                head = head->next;
            }
        }
        l_flag->next = NULL;
        r_flag->next = NULL;

        if (r_flag == r_head) { // <= 1 element
            return l_head->next;
        } else {
            l_flag = sortList(l_head->next);
            r_flag = sortList(r_head->next);
            
            ListNode* nhead = new ListNode(-1);
            ListNode* flag = nhead;
            while (l_flag != NULL and r_flag != NULL) {
                if (l_flag->val < r_flag->val) {
                    flag->next = l_flag;
                    flag = flag->next;
                    l_flag = l_flag->next;
                } else {
                    flag->next = r_flag;
                    flag = flag->next;
                    r_flag = r_flag->next;
                }
            }
            
            while (l_flag != NULL) {
                flag->next = l_flag;
                flag = flag->next;
                l_flag = l_flag->next;
            }
            
            while (r_flag != NULL) {
                flag->next = r_flag;
                flag = flag->next;
                r_flag = r_flag->next;
            }
            
            return nhead->next;
        }
    }
};
