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
    pair<int,int> dfs(TreeNode* root, int& mmax) {
        pair<int,int> ret = make_pair(root->val, 1);
        if (root->left != NULL) {
            pair<int,int> pl = dfs(root->left, mmax);
            if (root->val + 1 == pl.first) {
                ret.second = max(ret.second, pl.second + 1);
            }
        }
        if (root->right != NULL) {
            pair<int,int> pr = dfs(root->right, mmax);
            if (root->val + 1 == pr.first) {
                ret.second = max(ret.second, pr.second + 1);
            }
        }
        mmax = max(mmax, ret.second);
        return ret;
    }
    
    int longestConsecutive(TreeNode* root) {
        int mmax = 0;
        if (root == NULL) {
            return mmax;
        } else {
            dfs(root, mmax);
            return mmax;
        }
    }
};
