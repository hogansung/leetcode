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
    void dfs(vector<vector<int>>& vct, TreeNode* root, int dep) {
        if (dep == vct.size()) {
            vct.push_back(vector<int>());
        }
        vct[dep].push_back(root->val);
        
        if (root->left != NULL) {
            dfs(vct, root->left, dep+1);
        }
        if (root->right != NULL) {
            dfs(vct, root->right, dep+1);   
        }
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<int>> vct;
        dfs(vct, root, 0);
        
        vector<double> ret;
        for (int i = 0; i < vct.size(); i++) {
            double val = 0;
            for (int j = 0; j < vct[i].size(); j++) {
                val += vct[i][j];
            }
            ret.push_back(val / vct[i].size());
        }
        return ret;
    }
};
