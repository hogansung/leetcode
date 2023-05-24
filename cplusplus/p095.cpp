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
    vector<TreeNode*> dfs(int l, int r) {
        if (l > r) {
            return vector<TreeNode*>(1, NULL);
        } else {
            vector<TreeNode*> ret;
            for (int m = l; m <= r; m++) {
                vector<TreeNode*> ret_l = dfs(l, m-1);
                vector<TreeNode*> ret_r = dfs(m+1, r);
                
                for (int i = 0; i < ret_l.size(); i++) {
                    for (int j = 0; j < ret_r.size(); j++) {
                        TreeNode* root = new TreeNode(m);
                        root->left = ret_l[i];
                        root->right = ret_r[j];
                        ret.push_back(root);
                    }
                }
            }
            return ret;
        }
    }
    
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return vector<TreeNode*>();
        } else {
            vector<TreeNode*> ret = dfs(1, n);
            return ret;
        }
    }
};
