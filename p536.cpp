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
    TreeNode* dfs(string& s, int l, int r,
                  vector<int>& pos_lb, vector<int>& pos_rb) {
        if (l > r) {
            return NULL;
        } else {
            string num_s = "";
            while (s[l] != '(' and l <= r) {
                num_s.push_back(s[l]);
                l += 1;
            }

            TreeNode* root = new TreeNode(strtol(num_s.c_str(), 0, 10));
            if (l < r) {
                root->left = dfs(s, l+1, pos_lb[l]-1, pos_lb, pos_rb);
                if (pos_lb[l] != r) {
                    root->right = dfs(s, pos_rb[r]+1, r-1, pos_lb, pos_rb);
                }
            }
            return root;
        }
    }
    
    TreeNode* str2tree(string s) {
        int len = s.length();
        vector<int> pos_lb(len, -1);
        vector<int> pos_rb(len, -1);

        stack<int> st;
        for (int i = 0; i < len; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                assert(st.size() > 0);
                pos_lb[st.top()] = i;
                pos_rb[i] = st.top();
                st.pop();
            }
        }
        assert(st.size() == 0);

        return dfs(s, 0, len-1, pos_lb, pos_rb);
    }
};
