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
    string inStr(const TreeNode* root) {
        string str = "";
        if (root->left) str += "L" + inStr(root->left);
        str += "M" + to_string(root->val);
        if (root->right) str += "R" + inStr(root->right);
        return str;
    }
    
    void dfs(TreeNode* root, unordered_map<string, int>& um,
             unordered_map<string, TreeNode*>& treeMap) {
        um[inStr(root)] += 1;
        treeMap[inStr(root)] = root;
        if (root->left != NULL) dfs(root->left, um, treeMap);
        if (root->right != NULL) dfs(root->right, um, treeMap);
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> um;
        unordered_map<string, TreeNode*> treeMap;
        if (root != NULL) {
            dfs(root, um, treeMap);
        }
        
        vector<TreeNode*> ret;
        for (auto pv : um) {
            if (pv.second > 1) {
                ret.emplace_back(treeMap[pv.first]);
            }
        }
        return ret;
    }
};
