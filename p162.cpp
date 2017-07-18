class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        while (l < r) {
            int m = (l + r) / 2;
            long long lval = (m == 0) ?LLONG_MIN: nums[m-1];
            long long rval = (m == n-1) ?LLONG_MIN :nums[m+1];
            
            if (lval < nums[m] and nums[m] < rval) {
                l = m+1;
            } else {
                r = m;
            }
        }
        return l;
    }
};
