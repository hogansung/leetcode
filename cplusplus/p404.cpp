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
    int dfs(TreeNode* root, int st) {
        if (root == NULL) {
            return 0;
        } else if (root->left == NULL and root->right == NULL) {
            if (st == -1) {
                return root->val;
            }
        }
        
        int sum = 0;
        if (root->left != NULL) {
            sum += dfs(root->left, -1);
        }
        if (root->right != NULL) {
            sum += dfs(root->right, 1);
        }
        return sum;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root, 0);
    }
};
