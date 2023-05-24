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
    unordered_set<int> dfs(TreeNode* root, int& cnt) {
        unordered_set<int> us_l;
        if (root->left != NULL) {
            us_l = dfs(root->left, cnt);
        }
        
        unordered_set<int> us_r;
        if (root->right != NULL) {
            us_r = dfs(root->right, cnt);
        }
        
        unordered_set<int> us;
        for (auto v : us_l) {
            us.emplace(v);
        }
        for (auto v : us_r) {
            us.emplace(v);
        }
        us.emplace(root->val);
        
        if (us.size() == 1) {
            cnt += 1;
        }
        return us;
    }
    
    int countUnivalSubtrees(TreeNode* root) {
        if (root == NULL) {
            return 0;
        } else {
            int cnt = 0;
            dfs(root, cnt);
            return cnt;
        }
    }
};
