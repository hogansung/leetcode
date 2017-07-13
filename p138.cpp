/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode* createRandomListNode(RandomListNode* head, 
                              unordered_map<RandomListNode*,RandomListNode*>& um) {
        if (head == NULL) {
            return NULL;
        } else {
            if (um.find(head) == um.end()) {
                RandomListNode* nhead = new RandomListNode(head->label);
                um[head] = nhead;
            }
            return um[head];
        }
    }
    
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*,RandomListNode*> um;
        
        RandomListNode* ret;
        int cnt = 0;
        while (head != NULL) {
            RandomListNode* nhead = createRandomListNode(head, um);
            if (cnt == 0) {
                ret = nhead;
            }
            cnt += 1;
            nhead->next = createRandomListNode(head->next, um);
            nhead->random = createRandomListNode(head->random, um);
            head = head->next;
        }
        return ret;
    }
};
