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
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder,
                  int t, int l, int r) {
        if (l > r) {
            return NULL;
        } else {
            int m = l;
            while (inorder[m] != preorder[t]) {
                m += 1;
            }

            TreeNode* root = new TreeNode(preorder[t]);
            root->left = dfs(preorder, inorder, t+1, l, m-1);
            root->right = dfs(preorder, inorder, t+m-l+1, m+1, r);
            return root;
        }
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(preorder, inorder, 0, 0, preorder.size()-1);
    }
};
