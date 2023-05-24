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
    void dfs(vector<vector<int>>& ret, vector<int>& vct,
             TreeNode* root, int sum) {
        if (root == NULL) {
            // do nothing
        } else {
            vct.push_back(root->val);
            if (root->left == NULL and root->right == NULL and sum == root->val) {
                ret.emplace_back(vct);
            } else {
                dfs(ret, vct, root->left, sum-root->val);
                dfs(ret, vct, root->right, sum-root->val);
            }
            vct.pop_back();
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        vector<int> vct;
        dfs(ret, vct, root, sum);
        return ret;
    }
};
