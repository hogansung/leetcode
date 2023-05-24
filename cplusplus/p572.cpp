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
    bool check(TreeNode* s, TreeNode* t) {
        if (s == NULL and t == NULL) {
            return true;
        } else if (s != NULL and t != NULL) {
            return (check(s->left, t->left) and
                    check(s->right, t->right) and
                    s->val == t->val);
        } else {
            return false;
        }
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (check(s, t) == true) {
            return true;
        } else if (s != NULL) {
            return isSubtree(s->left, t) or
                   isSubtree(s->right, t);
        } else {
            return false;
        }
    }
};
