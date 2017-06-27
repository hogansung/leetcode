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
    bool dfs(TreeNode* root_l, TreeNode* root_r) {
        if (root_l == NULL and root_r == NULL) {
            return true;
        } else if (root_l == NULL or root_r == NULL) {
            return false;
        } else if (root_l->val != root_r->val) {
            return false;
        } else {
            return (dfs(root_l->left, root_r->right) and
                dfs(root_l->right, root_r->left));
        }
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        } else {
            return dfs(root->left, root->right);
        }
    }
};
