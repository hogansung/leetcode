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
    int dfs(TreeNode* root, 
            const int sum,
            vector<int>& vct) {
        if (root == NULL) {
            return 0;
        } else {
            int ret = 0;
            for (auto v : vct) {
                if (root->val + vct.back() - v == sum) {
                    ret += 1;
                }
            }
            vct.push_back(vct.back() + root->val);
            ret += dfs(root->left, sum, vct);
            ret += dfs(root->right, sum, vct);
            vct.pop_back();
            return ret;
        }
    }
    
    int pathSum(TreeNode* root, int sum) {
        vector<int> vct(1, 0);
        int ret = dfs(root, sum, vct);
        return ret;
    }
};
