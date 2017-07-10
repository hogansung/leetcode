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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 != NULL and t2 != NULL) {
            TreeNode* ret = new TreeNode(t1->val + t2->val);
            ret->left = mergeTrees(t1->left, t2->left);
            ret->right = mergeTrees(t1->right, t2->right);
            return ret;
        } else if (t1 != NULL) {
            TreeNode* ret = new TreeNode(t1->val);
            ret->left = mergeTrees(t1->left, NULL);
            ret->right = mergeTrees(t1->right, NULL);
            return ret;
        } else if (t2 != NULL) {
            TreeNode* ret = new TreeNode(t2->val);
            ret->left = mergeTrees(NULL, t2->left);
            ret->right = mergeTrees(NULL, t2->right);
            return ret;
        } else {
            return NULL;
        }
    }
};
