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
    TreeNode* dfs(TreeNode* root, 
                  TreeNode* lt,
                  TreeNode* rt) {
        if (root->left == NULL) {
            if (lt != NULL) {
                lt->left = lt->right = NULL;
            }
            if (rt != NULL) {
                rt->left = rt->right = NULL;
            }
            root->left = lt;
            root->right = rt;
            return root;
        } else {
            TreeNode* ret = dfs(root->left, root->right, root);
            if (lt != NULL) {
                lt->left = lt->right = NULL;
            }
            if (rt != NULL) {
                rt->left = rt->right = NULL;
            }
            root->left = lt;
            root->right = rt;
            return ret;
        }
    }
    
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (root == NULL or root->left == NULL) {
            return root;
        } else {
            return dfs(root->left, root->right, root);
        }
    }
};
