class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        while (l < r) {
            int m = (l+r) / 2;
            if (nums[l] <= nums[m]) {
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
            return -1;
        } else {
            return l;
        }
    }
};
