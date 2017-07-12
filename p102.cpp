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
    void dfs(vector<vector<int>>& ret, int dep, TreeNode* root) {
        if (root == NULL) {
            // do nothing
        } else {
            if (ret.size() == dep) {
                ret.push_back(vector<int>());
            }
            ret[dep].push_back(root->val);
            
            dfs(ret, dep+1, root->left);
            dfs(ret, dep+1, root->right);
        }
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        dfs(ret, 0, root);
        return ret;
    }
};
