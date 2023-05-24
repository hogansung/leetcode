class Solution {
public:
    bool dfs(vector<int>& preorder, int l, int r) {
        if (l > r) {
            return true;
        } else {
            int val = preorder[l];
            bool small = false;
            int idx = r + 1;
            bool suc = true;
            for (int i = r; i > l; i--) {
                if (preorder[i] > val) {
                    if (small == true) {
                        suc = false;
                    } else {
                        idx = i;
                    }
                } else {
                    small = true;
                }
            }
            suc &= dfs(preorder, l+1, idx-1);
            suc &= dfs(preorder, idx, r);
            return suc;
        }
    }
    
    bool verifyPreorder(vector<int>& preorder) {
        int n = preorder.size();
        if (n == 0) {
            return true;
        } else {
            return dfs(preorder, 0, n-1);
        }
    }
};
