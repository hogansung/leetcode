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
    void dfs(TreeNode* root, vector<vector<int>>& vct, int depth) {
        if (root == NULL) {
            return;
        } else {
            if (vct.size() == depth) {
                vct.emplace_back(vector<int>());
            }
            vct[depth].emplace_back(root->val);
            dfs(root->left, vct, depth+1);
            dfs(root->right, vct, depth+1);
        }
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> vct;
        dfs(root, vct, 0);
        reverse(vct.begin(), vct.end());
        return vct;
    }
};
