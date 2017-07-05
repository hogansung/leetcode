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
    ListNode* dfs(ListNode* head, ListNode* pre) {
        if (head->next == NULL) {
            head->next = pre;
            return head;
        } else {
            ListNode* ret = dfs(head->next, head);
            head->next = pre;
            return ret;
        }
    }
    
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        } else if (head->next == NULL) {
            return head;
        } else {
            ListNode* ret = dfs(head->next, head);
            head->next = NULL;
            return ret;
        }
    }
};
