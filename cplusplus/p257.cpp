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
    void dfs(vector<string>& ret, string& str, TreeNode* root) {
        int len = str.length();
        if (root->left == NULL and root->right == NULL) {
            str += to_string(root->val);
            ret.emplace_back(str);
        } else {
            str += to_string(root->val);
            str += "->";
            if (root->left != NULL) {
                dfs(ret, str, root->left);
            }
            if (root->right != NULL) {
                dfs(ret, str, root->right);
                
            }
        }
        while (str.length() > len) {
            str.pop_back();
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == NULL) {
            return vector<string>();
        } else {
            vector<string> ret;
            string str;
            dfs(ret, str, root);
            return ret;
        }
    }
};
