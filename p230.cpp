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
    struct NTreeNode {
        int val;
        int num;
        NTreeNode* left;
        NTreeNode* right;
        NTreeNode(int x) : val(x), num(0), left(NULL), right(NULL) {}
    };
    
    NTreeNode* buildNTree(TreeNode* root, int& num) {
        if (root == NULL) {
            return NULL;
        } else {
            NTreeNode* nroot = new NTreeNode(root->val);
            
            int l_num = 0;
            nroot->left = buildNTree(root->left, l_num);
            
            int r_num = 0;
            nroot->right = buildNTree(root->right, r_num);
            
            nroot->num = l_num + 1;
            num = l_num + r_num + 1;
            return nroot;
        }
    }
    
    int dfs(NTreeNode* nroot, int k) {
        if (k == nroot->num) {
            return nroot->val;  
        } else if (k < nroot->num) {
            assert(nroot->left != NULL);
            return dfs(nroot->left, k);
        } else {
            assert(nroot->right != NULL);
            return dfs(nroot->right, k-nroot->num);
        }
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int num = 0;
        NTreeNode* nroot = buildNTree(root, num);
        return dfs(nroot, k);
    }
};
