class Solution {
public:
    void dfs(vector<vector<int>>& ret, vector<int>& vct,
             const vector<int>& nums, int t, const int n) {
        if (t == n) {
            ret.emplace_back(vct);
        } else {
            dfs(ret, vct, nums, t+1, n);
            
            vct.emplace_back(nums[t]);
            dfs(ret, vct, nums, t+1, n);
            vct.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ret;
        vector<int> vct;
        dfs(ret, vct, nums, 0, n);
        return ret;
    }
};
