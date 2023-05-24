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
    void dfs(vector<int>& ret, TreeNode* root) {
        if (root->left != NULL) dfs(ret, root->left);
        ret.push_back(root->val);
        if (root->right != NULL) dfs(ret, root->right);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (root != NULL) {
            dfs(ret, root);
        }
        return ret;
    }
};
