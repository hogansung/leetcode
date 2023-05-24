class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            nums[i] += 1;
        }
        for (int i = 0; i < n; i++) {
            int val = abs(nums[i]) - 1;
            if (val < n) {
                nums[val] *= -1;
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i;
            }
        }
        return n;
    }
};
