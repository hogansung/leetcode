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
    TreeNode* dfs(vector<int>& inorder, vector<int>& postorder,
                  int t, int l, int r) {
        if (l > r) {
            return NULL;
        } else {
            int m = l;
            while (inorder[m] != postorder[t]) {
                m += 1;
            }

            TreeNode* root = new TreeNode(postorder[t]);
            root->left = dfs(inorder, postorder, t-(r-m)-1, l, m-1);
            root->right = dfs(inorder, postorder, t-1, m+1, r);
            return root;
        }
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return dfs(inorder, postorder, postorder.size()-1, 0, postorder.size()-1);
    }
};
