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
    void dfs(map<int,vector<pair<pair<int,int>,int>>>& mv,
             TreeNode* root, int pos, int dep, int& dfn) {
        dfn += 1;
        mv[pos].emplace_back(make_pair(dep, dfn), root->val);
        if (root->left != NULL) {
            dfs(mv, root->left, pos-1, dep+1, dfn);
        }
        if (root->right != NULL) {
            dfs(mv, root->right, pos+1, dep+1, dfn);
        }
    }
    
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int,vector<pair<pair<int,int>,int>>> mv;
        int dfn = 0;
        if (root != NULL) {
            dfs(mv, root, 0, 0, dfn);
        }
        
        vector<vector<int>> ret;
        for (auto p : mv) {
            auto vp = p.second;
            sort(vp.begin(), vp.end());
            
            vector<int> vct;
            for (auto v : vp) {
                vct.push_back(v.second);
            }
            ret.emplace_back(vct);
        }
        return ret;
    }
};
