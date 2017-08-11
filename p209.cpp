class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int mmin = INT_MAX;
        int sum = 0;
        for (int r = 0; r < n; r++) {
            sum += nums[r];
            if (sum >= s) {
                mmin = min(mmin, r - l + 1);
            }
            
            while (sum >= s) {
                sum -= nums[l];
                l += 1;
                if (sum >= s) {
                    mmin = min(mmin, r - l + 1);
                }
            }
        }
        
        if (mmin == INT_MAX) {
            return 0;
        } else {
            return mmin;
        }
    }
};
