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
    int dfs(TreeNode* root, int& mmax, pair<int,int>& bound) {
        if (root == NULL) {
            bound = make_pair(INT_MAX, INT_MIN);
            return 0;
        } else {
            pair<int,int> lb;
            int ret_l = dfs(root->left, mmax, lb);
            
            pair<int,int> rb;
            int ret_r = dfs(root->right, mmax, rb);
            
            bound.first = min(lb.first, root->val-1);
            bound.second = max(rb.second, root->val+1);
            
            if (ret_l == -1 or ret_r == -1 or
                lb.second > root->val or root->val > rb.first) {
                return -1;
            } else {
                int ret = ret_l + ret_r + 1;
                mmax = max(mmax, ret);
                return ret;
            }
        }
    }
    
    int largestBSTSubtree(TreeNode* root) {
        int mmax = 0;
        if (root != NULL) {
            pair<int,int> bound;
            dfs(root, mmax, bound);
        }
        return mmax;
    }
};
