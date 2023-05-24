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
    int dfs(TreeNode* root, unordered_map<int,int>& um) {
        if (root == NULL) {
            return 0;
        } else {
            int sum = root->val;
            sum += dfs(root->left, um);
            sum += dfs(root->right, um);
            um[sum] += 1;
            return sum;
        }
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> um;
        dfs(root, um);
        
        int mmax = 0;
        vector<int> ret;
        for (auto p : um) {
            if (p.second > mmax) {
                mmax = p.second;
                ret = vector<int>(1, p.first);
            } else if (p.second == mmax) {
                ret.push_back(p.first);
            }
        }
        return ret;
    }
};
