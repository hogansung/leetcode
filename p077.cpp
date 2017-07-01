class Solution {
public:
    void dfs(vector<vector<int>>& ret, vector<int>& vct,
             vector<bool>& used, int t, const int k, const int n) {
        if (vct.size() == k) {
            ret.emplace_back(vct);
        } else {
            for (int i = t; i < n; i++) {
                if (used[i] == false) {
                    used[i] = true;
                    vct.emplace_back(i+1);
                    dfs(ret, vct, used, i+1, k, n);
                    used[i] = false;
                    vct.pop_back();
                }
            }
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> vct;
        vector<bool> used(n, false);
        dfs(ret, vct, used, 0, k, n);
        return ret;
    }
};
