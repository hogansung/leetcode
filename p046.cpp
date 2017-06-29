class Solution {
public:
    void dfs(vector<vector<int>>& ret, vector<int>& vct,
             const vector<int>& nums, vector<bool>& used,
             const int n) {
        if (vct.size() == n) {
            ret.emplace_back(vct);
        } else {
            for (int i = 0; i < n; i++) {
                if (used[i] == false) {
                    used[i] = true;
                    vct.emplace_back(nums[i]);
                    dfs(ret, vct, nums, used, n);
                    used[i] = false;
                    vct.pop_back();
                }
            }
        }
     }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ret;
        vector<int> vct;
        vector<bool> used(n, false);
        dfs(ret, vct, nums, used, n);
        return ret;
    }
};
