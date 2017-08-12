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
            return calDepth(root->left) + 1;
        }
    }
    
    bool check(TreeNode* root, vector<int>& vct, 
               int t, const int dep) {
        if (t == dep) {
            return root != NULL;
        } else {
            if (vct[t] == 0) {
                return check(root->left, vct, t+1, dep);
            } else {
                return check(root->right, vct, t+1, dep);
            }
        }
    }
    
    int countNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        } else {
            int dep = calDepth(root) - 1;
            int l = 0;
            int r = (1 << dep) - 1;

            while (l < r) {
                int m = (l + r) / 2 + 1;

                vector<int> vct(dep, 0);
                int val = m;
                for (int i = 0; i < dep; i++) {
                    vct[dep-1-i] = val % 2;
                    val /= 2;
                }

                bool suc = check(root, vct, 0, dep);
                if (suc == true) {
                    l = m;
                } else {
                    r = m-1;
                }
            }
            return (1 << dep) + l;
        }
    }
};
