class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int p = 0;
        while (p <= r) {
            if (nums[p] == 0) {
                swap(nums[p], nums[l]);
                l += 1;
                p = max(p, l);
            } else if (nums[p] == 2) {
                swap(nums[p], nums[r]);
                r -= 1;
            } else {
                p += 1;
            }
        }
    }
};
