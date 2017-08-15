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
    int dfs(TreeNode* root, TreeNode*& ret,
            TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return 0;
        } else {
            int val = 0;
            val |= dfs(root->left, ret, p, q);
            val |= dfs(root->right, ret, p, q);
            if (root == p) {
                val |= 1;
            } else if (root == q) {
                val |= 2;
            }
            
            if (val == 3 and ret == NULL) {
                ret = root;
            }
            return val;
        }
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ret = NULL;
        dfs(root, ret, p, q);
        assert(ret != NULL);
        return ret;
    }
};
