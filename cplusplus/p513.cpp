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
    void dfs(TreeNode* root, int dep, vector<int>& vct) {
        if (root == NULL) {
            return;
        } else {
            if (vct.size() == dep) {
                vct.push_back(root->val);
            }
            dfs(root->left, dep+1, vct);
            dfs(root->right, dep+1, vct);
        }
    }
    
    int findBottomLeftValue(TreeNode* root) {
        vector<int> vct;
        dfs(root, 0, vct);
        return vct.back();
    }
};
