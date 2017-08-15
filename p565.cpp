class Solution {
public:
    int dfs(int t, vector<int>& nums, vector<bool>& vis) {
        vis[t] = true;
        
        int ret = 0;
        int nt = nums[t];
        if (vis[nt] == false) {
            ret = dfs(nt, nums, vis) + 1;
        } else {
            ret = 1;
        }
        return ret;
    }
    
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<bool> vis(n, false);
        
        int mmax = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i] == false) {
                int ret = dfs(i, nums, vis);
                mmax = max(mmax, ret);
            }
        }
        return mmax;
    }
};
