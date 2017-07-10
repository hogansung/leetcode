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
    int calDep(TreeNode* root) {
        if (root == NULL) {
            return 0;
        } else {
            root->val = max(calDep(root->left),
                            calDep(root->right)) + 1;
            return root->val;
        }
    }
    
    void dfs(TreeNode* root, int val, int& mmax) {
        int dep_l = (root->left == NULL) ?0 :root->left->val;
        int dep_r = (root->right == NULL) ?0 :root->right->val;
        mmax = max(mmax, dep_l + dep_r + 1);
        mmax = max(mmax, dep_l + val + 1);
        mmax = max(mmax, dep_r + val + 1);
        
        if (root->left != NULL) {
            dfs(root->left, max(val,dep_r)+1, mmax);
        }
        if (root->right != NULL) {
            dfs(root->right, max(val,dep_l)+1, mmax);
        }
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        calDep(root);
        
        if (root == NULL) {
            return 0;
        } else {
            int mmax = 0;
            dfs(root, 0, mmax);
            return mmax-1;
        }
    }
};
