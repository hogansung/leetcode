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
    int calSum(TreeNode* root) {
        if (root == NULL) {
            return 0;
        } else {
            root->val += calSum(root->left) +
                         calSum(root->right);
            return root->val;
        }
    }
    
    int calTilt(TreeNode* root) {
        if (root == NULL) {
            return 0;
        } else {
            int ret = 0;
            ret += calTilt(root->left);
            ret += calTilt(root->right);
            
            int sum_l = (root->left == NULL) ?0 : root->left->val;
            int sum_r = (root->right == NULL) ?0 : root->right->val;
            ret += abs(sum_l - sum_r);
            return ret;
        }
    }
    
    int findTilt(TreeNode* root) {
        calSum(root);
        return calTilt(root);
    }
};
