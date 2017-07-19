class Solution {
public:
    const double DBL_MAX = 1.79769e+308;
    
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double mmax = -DBL_MAX;
        double sum = 0;
        printf("%d\n", n);
        for (int i = 0; i < n; i++) {
            if (i >= k) {
                sum -= nums[i-k];
            }
            sum += nums[i];
            if (i >= k-1) {
                mmax = max(mmax, sum / k);
            }
        }
        return mmax;
    }
};
