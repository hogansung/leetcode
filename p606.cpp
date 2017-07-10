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
    string tree2str(TreeNode* t) {
        string ret;
        if (t == NULL) {
            return ret;
        } else {
            ret += to_string(t->val);
            if (t->left != NULL and t->right != NULL) {
                ret += "(";
                ret += tree2str(t->left);
                ret += ")";
                ret += "(";
                ret += tree2str(t->right);
                ret += ")";
            } else if (t->left != NULL) {
                ret += "(";
                ret += tree2str(t->left);
                ret += ")";
            } else if (t->right != NULL) {
                ret += "(";
                ret += ")";
                ret += "(";
                ret += tree2str(t->right);
                ret += ")";
            } else {
                // do nothing
            }
            return ret;
        }
    }
};
