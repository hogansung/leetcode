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
    int dfs(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& ret) {
        if (root == NULL) {
            return 0;
        } else {
            int st_l = dfs(root->left, p, q, ret);
            int st_r = dfs(root->right, p, q, ret);
            if (st_l == 3 or st_r == 3) {
                return 3;
            } else {
                int st = st_l | st_r;
                if (root == p) {
                    st |= 1;
                } else if (root == q) {
                    st |= 2;
                }
                if (st == 3) {
                    ret = root;
                }
                return st;
            }
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ret;
        int st = dfs(root, p, q, ret);
        assert(st == 3);
        return ret;
    }
};
