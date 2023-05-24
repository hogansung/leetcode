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
    void dfs(vector<int>& ret, TreeNode* root, int dep) {
        if (ret.size() == dep) {
            ret.push_back(root->val);
        }
        if (root->right != NULL) dfs(ret, root->right, dep+1);
        if (root->left != NULL) dfs(ret, root->left, dep+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if (root != NULL) {
            dfs(ret, root, 0);
        }
        return ret;
    }
};
