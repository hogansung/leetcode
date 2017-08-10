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
    int calDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        } else {
            return max(calDepth(root->left), calDepth(root->right)) + 1;
        }
    }
    
    void dfs(vector<vector<string>>& ret, TreeNode* root, 
             int dep, const int maxDepth, int pos) {
        ret[dep][pos] = to_string(root->val);
        if (root->left != NULL) {
            dfs(ret, root->left, dep+1, maxDepth, pos-(1 << (maxDepth - dep - 2)));
        }
        if (root->right != NULL) {
            dfs(ret, root->right, dep+1, maxDepth, pos+(1 << (maxDepth - dep - 2)));
        }
    }
    
    vector<vector<string>> printTree(TreeNode* root) {
        int maxDepth = calDepth(root);
        vector<vector<string>> ret(maxDepth, vector<string>((1 << maxDepth) - 1, ""));
        
        dfs(ret, root, 0, maxDepth, (1 << (maxDepth - 1)) - 1);
        return ret;
    }
};
