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
    int calDepth(ListNode* flag) {
		int cnt = 0;
        while (flag != NULL) {
            flag = flag->next;
            cnt += 1;
        }
        return cnt;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int depA = calDepth(headA);
        int depB = calDepth(headB);
        if (depA < depB) {
        	for (int i = 0; i < depB - depA; i++) {
               	headB = headB->next;
            }
        } else {
            for (int i = 0; i < depA - depB; i++) {
                headA = headA->next;
            }
        }
		
        while (headA != NULL) {
        	if (headA == headB) {
                return headA;
            } else {
                headA = headA->next;
                headB = headB->next;
            }
        }
        return NULL;
    }
};
