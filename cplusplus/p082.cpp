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
            return NULL;
        } else {
            ListNode* nhead = new ListNode(-1);
            ListNode* flag = nhead;

            int val = head->val;
            int cnt = 1;
            while (head->next != NULL) {
				head = head->next;
                if (head->val == val) {
                    cnt += 1;
                } else {
                    if (cnt == 1) {
                        flag->next = new ListNode(val);
                        flag = flag->next;
                    }
                    val = head->val;
                    cnt = 1;
                }
            }
            if (cnt == 1) {
                flag->next = new ListNode(val);
                flag = flag->next;
            }
            return nhead->next;
        }
    }
};
