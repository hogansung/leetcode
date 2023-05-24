/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) {
            // do nothing
        } else {
            queue<pair<TreeLinkNode*,int>> qp;
            qp.emplace(root, 0);

            while (qp.size()) {
                auto p = qp.front(); qp.pop();
                if (p.first->left != NULL) {
                    if (qp.size() and qp.back().second == p.second+1) {
                        qp.back().first->next = p.first->left;
                    }
                    qp.emplace(p.first->left, p.second+1);
                }
                if (p.first->right != NULL) {
                    if (qp.size() and qp.back().second == p.second+1) {
                        qp.back().first->next = p.first->right;
                    }
                    qp.emplace(p.first->right, p.second+1);
                }
            }
        }
    }
};
