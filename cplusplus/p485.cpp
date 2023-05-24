class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int mmax = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                cnt += 1;
            } else {
                mmax = max(mmax, cnt);
                cnt = 0;
            }
        }
        mmax = max(mmax, cnt);
        return mmax;
    }
};
