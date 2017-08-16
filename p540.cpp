class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        nums.push_back(INT_MIN);
        int l = 0;
        int r = nums.size() / 2 - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (nums[2*m] == nums[2*m+1]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return nums[2*l];
    }
};
