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
    void dfs(unordered_map<int,int>& um, TreeNode* root) {
        if (root->left != NULL) dfs(um, root->left);
        um[root->val] += 1;
        if (root->right != NULL) dfs(um, root->right);
    }
    
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int> um;
        if (root != NULL) {
            dfs(um, root);
        }
        
        for (auto p : um) {
            if (p.first * 2 == k) {
                if (p.second >= 2) {
                    return true;
                }
            } else if (um.find(k - p.first) != um.end()) {
                return true;
            }
        }
        return false;
    }
};
