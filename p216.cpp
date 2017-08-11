class Solution {
public:
    void dfs(vector<vector<int>>& ret, 
            vector<int>& vct, int last, int k, int n) {
        if (k == 0 and n == 0) {
            ret.emplace_back(vct);
        } else if (k == 0 or n == 0) {
            // do nothing
        } else {
            for (int i = last; i <= 9; i++) {
                if (n >= i) {
                    vct.push_back(i);
                    dfs(ret, vct, i+1, k-1, n-i);
                    vct.pop_back();
                }
            }
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
        vector<int> vct;
        dfs(ret, vct, 1, k, n);
        return ret;
    }
};
