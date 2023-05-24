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
    void dfs_l(vector<int>& ret, TreeNode* root) {
        if (root->left == NULL and root->right == NULL) {
            return;
        } else {
            ret.push_back(root->val);
            if (root->left != NULL) {
                dfs_l(ret, root->left);
            } else if (root->right != NULL) {
                dfs_l(ret, root->right);
            }
        }
    }
    
    void dfs(vector<int>& ret, TreeNode* root) {
        if (root->left == NULL and root->right == NULL) {
            ret.push_back(root->val);
        } else {
            if (root->left != NULL) {
                dfs(ret, root->left);
            }
            if (root->right != NULL) {
                dfs(ret, root->right);
            }
        }
    }
    
    void dfs_r(vector<int>& ret, TreeNode* root) {
        if (root->left == NULL and root->right == NULL) {
            return;
        } else {
            if (root->right != NULL) {
                dfs_r(ret, root->right);
            } else if (root->left != NULL) {
                dfs_r(ret, root->left);
            }
            ret.push_back(root->val);
        }
    }
    
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return vector<int>();
        } else {
            vector<int> ret;
            ret.push_back(root->val);
            if (root->left != NULL) {
                dfs_l(ret, root->left);
            }
            if (root->left != NULL or root->right != NULL) {
                dfs(ret, root);
            }
            if (root->right != NULL) {
                dfs_r(ret, root->right);
            }
            return ret;
        }
    }
};
