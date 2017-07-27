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
    void dfs(TreeNode* root, int& inc, int& dec, int& mmax) {
        int l_inc = 0;
        int l_dec = 0;
        if (root->left != NULL) {
            dfs(root->left, l_inc, l_dec, mmax);
        }
        
        int r_inc = 0;
        int r_dec = 0;
        if (root->right != NULL) {
            dfs(root->right, r_inc, r_dec, mmax);
        }
        
        inc = dec = 1;
        if (root->left != NULL and root->right != NULL) {
            if (root->left->val + 1 == root->val and
                root->val + 1 == root->right->val) {
                mmax = max(mmax, l_inc + 1 + r_dec);
            } else if (root->left->val - 1 == root->val and
                root->val - 1 == root->right->val) {
                mmax = max(mmax, l_dec + 1 + r_inc);
            }
        }
        if (root->left != NULL) {
            if (root->left->val + 1 == root->val) {
                inc = max(inc, l_inc + 1);
                
            } else if (root->left->val - 1 == root->val) {
                dec = max(dec, l_dec + 1);
            }
        }
        if (root->right != NULL) {
            if (root->right->val + 1 == root->val) {
                inc = max(inc, r_inc + 1);
            } else if (root->right->val - 1 == root->val) {
                dec = max(dec, r_dec + 1);
            }
        }
        
        mmax = max(mmax, inc);
        mmax = max(mmax, dec);
    }
    
    int longestConsecutive(TreeNode* root) {
        if (root == NULL) {
            return 0;
        } else {
            int inc, dec, mmax = 0;
            dfs(root, inc, dec, mmax);
            return mmax;
        }
    }
};
