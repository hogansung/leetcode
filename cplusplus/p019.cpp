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
    int dfs(ListNode* head, int n) {
        if (head == NULL) {
            return 0;
        } else {
            int dep = dfs(head->next, n);
            if (dep == n) {
                head->next = head->next->next;
            }
            return dep+1;
        }
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* nhead = new ListNode(-1);
        nhead->next = head;
        dfs(nhead, n);
        return nhead->next;
    }
};
