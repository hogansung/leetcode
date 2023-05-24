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
    int dfs(TreeNode* root, int v) {
        if (root == NULL) {
            return 0;
        } else if (root->left == NULL and root->right == NULL) {
            return 10 * v + root->val;
        } else {
            int sum = 0;
            sum += dfs(root->left, 10 * v + root->val);
            sum += dfs(root->right, 10 * v + root->val);
            return sum;
        }
    }
    
    int sumNumbers(TreeNode* root) {
        if (root == NULL) {
            return 0;
        } else {
            return dfs(root, 0);
        }
    }
};
