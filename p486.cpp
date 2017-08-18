class Solution {
public:
    int dp(int t, int l, int r, vector<int>& nums, 
           vector<vector<vector<int>>>& rcd) {
        if (l > r) {
            return 0;
        } else {
            int mmax = INT_MIN;
            mmax = max(mmax, nums[l] - dp(1-t, l+1, r, nums, rcd));
            mmax = max(mmax, nums[r] - dp(1-t, l, r-1, nums, rcd));
            return rcd[t][l][r] = mmax;
        }
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> rcd(2, vector<vector<int>>(n, vector<int>(n, -1)));
        return dp(0, 0, n-1, nums, rcd) >= 0;
    }
};
