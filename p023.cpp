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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        
        ListNode* head = new ListNode(-1);
        ListNode* flag = head;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for (int i = 0; i < n; i++) {
            if (lists[i] != NULL) {
                pq.emplace(lists[i]->val, i);
                lists[i] = lists[i]->next;
            }
        }
        
        while (pq.size()) {
            pair<int,int> pp = pq.top(); pq.pop();
            flag->next = new ListNode(pp.first);
            flag = flag->next;
            if (lists[pp.second] != NULL) {
                pq.emplace(lists[pp.second]->val, pp.second);
                lists[pp.second] = lists[pp.second]->next;
            }
        }
        return head->next;
    }
};
