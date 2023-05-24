class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        long long ret = INT_MAX;
        for (int i = 0; i < n; i++) {
            int l = i+1;
            int r = n-1;
            while (l < r) {
                int val = nums[i] + nums[l] + nums[r];
                if (abs(ret - target) > abs(val - target)) {
                    ret = val;
                }
                
                if (val < target) {
                    l += 1;   
                } else {
                    r -= 1;
                }
            }
        }
        return ret;
    }
};
