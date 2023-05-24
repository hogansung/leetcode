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
    ListNode* reverseListNode(ListNode* head, ListNode* pre) {
        if (head->next == NULL) {
            head->next = pre;
            return head;
        } else {
            ListNode* ret = reverseListNode(head->next, head);
            head->next = pre;
            return ret;
        }
    }
    
    ListNode* plusOne(ListNode* head) {
        head = reverseListNode(head, NULL);
        
        ListNode* flag = head;
        ListNode* last;
        int cry = 1;
        while (flag != NULL and cry) {
            int sum = flag->val + cry;
            flag->val = sum % 10;
            cry = sum / 10;
            last = flag;
            flag = flag->next;
        }
        if (cry) {
            last->next = new ListNode(cry);
        }
        
        return reverseListNode(head, NULL);
    }
};
