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
    void dfs(vector<int>& vct, TreeNode* root) {
        if (root->right != NULL) {
            dfs(vct, root->right);
        }
        vct.push_back(root->val);
        if (root->left != NULL) {
            dfs(vct, root->left);
        }
    }
    
    int getMinimumDifference(TreeNode* root) {
        vector<int> vct;
        dfs(vct, root);
        
        int n = vct.size();
        int ret = INT_MAX;
        for (int i = 0; i < n-1; i++) {
            ret = min(ret, vct[i] - vct[i+1]);
        }
        return ret;
    }
};
