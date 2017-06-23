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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* flag = head;
        while (l1 != NULL or l2 != NULL) {
            if (l1 != NULL and l2 != NULL) {
                if (l1->val < l2->val) {
                    flag->next = new ListNode(l1->val);
                    flag = flag->next;
                    l1 = l1->next;
                } else {
                    flag->next = new ListNode(l2->val);
                    flag = flag->next;
                    l2 = l2->next;
                }
            } else if (l1 != NULL) {
                flag->next = new ListNode(l1->val);
                flag = flag->next;
                l1 = l1->next;
            } else if (l2 != NULL) {
                flag->next = new ListNode(l2->val);
                flag = flag->next;
                l2 = l2->next;
            }
        }
        return head->next;
    }
};
