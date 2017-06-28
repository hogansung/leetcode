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
    bool hasCycle(ListNode *head) {
        ListNode* ptr_s = head;
        ListNode* ptr_d = head;
        do {
            if (ptr_s == NULL or 
                ptr_d == NULL or 
                ptr_d->next == NULL) {
                return false;
            }
            ptr_s = ptr_s->next;
            ptr_d = ptr_d->next->next;
        } while (ptr_d != ptr_s);
        return true;
    }
};
