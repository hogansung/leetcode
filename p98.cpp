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
    bool dfs(TreeNode* root, long long mmin, long long mmax) {
        if (root == NULL) {
            return true;
        } else {
            bool suc = true;
            suc &= dfs(root->left, mmin, root->val);
            suc &= dfs(root->right, root->val, mmax);
            suc &= mmin < root->val;
            suc &= root->val < mmax;
            return suc;
        }
    }
    
    bool isValidBST(TreeNode* root) {
        return dfs(root, LLONG_MIN, LLONG_MAX);
    }
};
