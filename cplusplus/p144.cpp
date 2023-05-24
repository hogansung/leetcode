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
        ret.push_back(root->val);
        if (root->left != NULL) dfs(ret, root->left);
        if (root->right != NULL) dfs(ret, root->right);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (root == NULL) {
            return ret;
        } else {
            dfs(ret, root);
            return ret;
        }
    }
};
