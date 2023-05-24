class Solution {
public:
    const int MAGIC = 2147483647;

    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        while (r < n) {
            int val = nums[r];
            nums[l] = val;
            l += 1;
            r += 1;
            while (r < n and val == nums[r]) {
                r += 1;
            }
        }
        return l;
    }
};
