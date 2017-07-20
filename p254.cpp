class Solution {
public:
    void dfs(vector<vector<int>>& ret, vector<int>& vct,
             int t, int lb, int ub, int val) {
        if (val == 1) {
            return;
        } else {
            if (t > 0 and val >= lb) {
                vct.push_back(val);
                ret.emplace_back(vct);
                vct.pop_back();
            }
            
            for (int i = lb; i <= ub; i++) {
                if (val % i == 0) {
                    vct.push_back(i);
                    dfs(ret, vct, t+1, i, ub, val/i);
                    vct.pop_back();
                }
            }
        }
    }
    
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> ret;
        vector<int> vct;
        dfs(ret, vct, 0, 2, sqrt(n), n);
        return ret;
    }
};
