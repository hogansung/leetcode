class Solution {
public:
    void dfs(vector<vector<int>>& ret, vector<int>& vct,
      const vector<int>& candidates, const int n, int flag, int target) {
        if (target == 0) {
            ret.emplace_back(vct);
        } else if (flag == n) {
            // do nothing
        } else {
            if (candidates[flag] <= target) {
                vct.push_back(candidates[flag]);
                dfs(ret, vct, candidates, n, flag, target-candidates[flag]);
                vct.pop_back();
            }
            dfs(ret, vct, candidates, n, flag+1, target);
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ret;
        vector<int> vct;
        dfs(ret, vct, candidates, n, 0, target);
        return ret;
    }
};
