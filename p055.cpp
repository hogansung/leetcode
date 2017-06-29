class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int mmax = 0;
        for (int i = 0; i <= mmax and i < n; i++) {
            mmax = max(mmax, i+nums[i]);
        }
        return mmax >= n-1;
    }
};
