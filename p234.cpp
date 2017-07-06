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
    int calDepth(ListNode* head) {
        if (head == NULL) {
            return 0;
        } else {
            return calDepth(head->next) + 1;
        }
    }
    
    ListNode* getTail(ListNode* head, ListNode* pre,
                      int t, const int dep) {
        if (head->next == NULL) {
            head->next = pre;
            return head;
        } else {
            ListNode* ret = getTail(head->next, head, t+1, dep);
            if (t == dep/2-1) {
                head->next = NULL;
            } else if (t == (dep+1)/2) {
                head->next = NULL;
            } else if (t > (dep+1)/2) {
                head->next = pre;
            }
            return ret;
        }
    }
    
    bool isPalindrome(ListNode* head) {
        int dep = calDepth(head);
        if (dep == 0 or dep == 1) {
            return true;
        } else {
            ListNode* tail = getTail(head, NULL, 0, dep);
            while (head != NULL) {
                assert(tail != NULL);
                if (head->val != tail->val) {
                    return false;
                }
                head = head->next;
                tail = tail->next;
            }
            return true;
        }
    }
};
