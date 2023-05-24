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
    TreeNode* dfs(vector<int>& nums, int l, int r) {
        if (l > r) {
            return NULL;
        } else {
            int mmin = INT_MIN;
            int idx = -1;
            for (int i = l; i <= r; i++) {
                if (nums[i] > mmin) {
                    mmin = nums[i];
                    idx = i;
                }
            }
            
            TreeNode* root = new TreeNode(nums[idx]);
            root->left = dfs(nums, l, idx-1);
            root->right = dfs(nums, idx+1, r);
            return root;
        }
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        return dfs(nums, 0, n-1);
    }
};
