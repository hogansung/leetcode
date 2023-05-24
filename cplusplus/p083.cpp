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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) {
            return head;
        } else {
            ListNode* flag = head;
            while (flag != NULL) {
                while (flag->next != NULL and 
                       flag->val == flag->next->val) {
                    flag->next = flag->next->next;
                }
                flag = flag->next;
            }
            return head;
        }
    }
};
