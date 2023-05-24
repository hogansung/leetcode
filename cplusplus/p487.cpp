class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        bool zero = false;
        int sum_f = 0;
        int sum_s = 0;
        int mmax = 0;
        for (auto num : nums) {
            if (num == 1) {
                sum_s += 1;
            } else {
                zero = true;
                mmax = max(mmax, sum_f + 1 + sum_s);
                sum_f = sum_s;
                sum_s = 0;
            }
        }
        
        if (zero == false) {
            mmax = max(mmax, sum_s);
        } else {
            mmax = max(mmax, sum_f + 1 + sum_s);
        }
        
        return mmax;
    }
};
