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
    TreeNode* createTree(vector<int>& nums, int l, int r) {
        if (l > r) {
            return NULL;
        } else {
            int m = (l+r) / 2;
            TreeNode* ret = new TreeNode(nums[m]);
            ret->left = createTree(nums, l, m-1);
            ret->right = createTree(nums, m+1, r);
            return ret;
        }
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createTree(nums, 0, nums.size()-1);
    }
};
