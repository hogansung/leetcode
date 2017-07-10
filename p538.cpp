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
    void dfs(int& sum, TreeNode* root) {
        if (root->right != NULL) {
            dfs(sum, root->right);
        }
        sum += root->val;
        root->val += sum - root->val;
        if (root->left != NULL) {
            dfs(sum, root->left);
        }
    }
    
    TreeNode* convertBST(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        } else {
            int sum = 0;
            dfs(sum, root);
            return root;
        }
    }
};
