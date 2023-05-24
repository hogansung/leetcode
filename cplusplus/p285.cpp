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
    void findNode(stack<TreeNode*>& st,
                  TreeNode* root, TreeNode* p) {
        if (p->val < root->val) {
            st.push(root);
            findNode(st, root->left, p);
        } else if (p->val > root->val) {
            findNode(st, root->right, p);
        } else {
            // do nothing
        }
    }
    
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (p->right != NULL) {
            p = p->right;
            while (p->left != NULL) {
                p = p->left;
            }
            return p;
        } else {
            stack<TreeNode*> st;
            findNode(st, root, p);     
            if (st.size() == 0) {
                return NULL;
            } else {
                return st.top();
            }
        }
    }
};
