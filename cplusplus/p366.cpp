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
    int dfs(vector<vector<int>>& ret, TreeNode* root) {
        if (root == NULL) {
            return 0;
        } else {
            int dep = 0;
            dep = max(dep, dfs(ret, root->left));
            dep = max(dep, dfs(ret, root->right));
            if (ret.size() == dep) {
                ret.emplace_back(vector<int>());
            }
            ret[dep].push_back(root->val);
            return dep+1;
        }
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ret;
        dfs(ret, root);
        return ret;
    }
};
