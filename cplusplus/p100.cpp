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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL and q == NULL) {
            return true;
        } else if (p == NULL or q == NULL) {
            return false;
        } else if (p->val != q->val) {
            return false;
        } else {
            return (isSameTree(p->left, q->left) == true and
                isSameTree(p->right, q->right) == true);
        }
    }
};
