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
    
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* nhead = new ListNode(-1);
        nhead->next = head;
        
        ListNode* f_flag = nhead;
        for (int i = 0; i < m-1; i++) { // the one before reversing block
            f_flag = f_flag->next;
        }
        
        ListNode* s_flag = nhead;
        for (int i = 0; i < n; i++ ) { // the last element in reversing block
            s_flag = s_flag->next;
        }
        
        ListNode* target = s_flag->next; // the next element for reversing block
        s_flag->next = NULL;
        
        ListNode* rhead = dfs(f_flag->next, target);
        f_flag->next = rhead;
        return nhead->next;
    }
};
