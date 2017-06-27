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
    pair<bool,int> verify(TreeNode* root) {
        if (root == NULL) {
            return make_pair(true, 0);
        } else {
            pair<bool,int> pl = verify(root->left);
            pair<bool,int> pr = verify(root->right);
            return make_pair(
                pl.first and pr.first and abs(pl.second-pr.second) <= 1,
                max(pl.second, pr.second)+1
            );
        }
    }

    bool isBalanced(TreeNode* root) {
        pair<bool,int> pp = verify(root);
        return pp.first;
    }
};
