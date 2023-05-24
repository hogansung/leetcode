/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
const double DBL_MAX = 1.79769e+308;

class Solution {
public:
    void dfs(pair<double,int>& pv, TreeNode* root, double target) {
        pv = min(pv, make_pair(abs(root->val-target), root->val));
        if (target < root->val) {
            if (root->left != NULL) {
                dfs(pv, root->left, target);
            }
        } else {
            if (root->right != NULL) {
                dfs(pv, root->right, target);
            }
        }
    }
    
    int closestValue(TreeNode* root, double target) {
        pair<double,int> pv(DBL_MAX, -1);
        dfs(pv, root, target);
        return pv.second;
    }
};
