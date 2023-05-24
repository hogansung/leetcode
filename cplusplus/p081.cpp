class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        while (l < r) {
            int m = (l+r) / 2;
            // if all three pivots are the same,
            // there is no way to make the decision
            if (nums[l] == nums[m] and nums[m] == nums[r]) {
                r -= 1;
            } else if (nums[l] <= nums[m]) {
                if (nums[l] <= target and target <= nums[m]) {
                    r = m;
                } else {
                    l = m+1;
                }
            } else {
                if (nums[m] < target and target <= nums[r]) {
                    l = m+1;
                } else {
                    r = m;
                }
            }
        }
        
        if (n == 0 or nums[l] != target) {
            return false;
        } else {
            return true;
        }
    }
};
