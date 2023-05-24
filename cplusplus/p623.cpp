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
    void dfs(TreeNode* root, int dep, int v, int d) {
        if (dep == d-1) {
            TreeNode* l_tmp = root->left;
            root->left = new TreeNode(v);
            root->left->left = l_tmp;
            
            TreeNode* r_tmp = root->right;
            root->right = new TreeNode(v);
            root->right->right = r_tmp;
        } else {
            if (root->left != NULL) dfs(root->left, dep+1, v, d);
            if (root->right != NULL) dfs(root->right, dep+1, v, d);
        }
    }
    
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode* nroot = new TreeNode(v);
            nroot->left = root;
            return nroot;
        } else {
            dfs(root, 1, v, d);
            return root;
        }
    }
};
