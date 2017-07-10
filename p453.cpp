class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int mmin = INT_MAX;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            mmin = min(mmin, nums[i]);
            sum += nums[i];
        }
        return sum - (long long)mmin * n;
    }
};
