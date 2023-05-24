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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) {
            return NULL;
        } else {
            ListNode* sn = head;
            ListNode* dn = head;
            
            bool suc = false;
            while (sn->next != NULL and 
                   dn->next != NULL and
                   dn->next->next != NULL) {
                sn = sn->next;
                dn = dn->next->next;
                if (sn == dn) {
                    suc = true;
                    break;
                }
            }
            
            if (suc == true) {
                ListNode* nn = head;
                while (nn != sn) {
                    nn = nn->next;
                    sn = sn->next;
                }
                return nn;
            } else {
                return NULL;
            }
        }
    }
};
