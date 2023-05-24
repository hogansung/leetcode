/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* dfs(vector<int>& vct, int l, int r) {
        if (l > r) {
            return NULL;
        } else {
            int m = (l+r) / 2;
            TreeNode* root = new TreeNode(vct[m]);
            root->left = dfs(vct, l, m-1);
            root->right = dfs(vct, m+1, r);
            return root;
        }
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> vct;
        while (head != NULL) {
            vct.push_back(head->val);
            head = head->next;
        }
        
        return dfs(vct, 0, vct.size()-1);
    }
};
