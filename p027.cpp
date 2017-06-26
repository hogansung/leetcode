class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        while (r < n) {
            while (r < n and nums[r] == val) {
                r += 1;
            }
            
            if (r == n) {
                break;
            } else {
                nums[l] = nums[r];
                l += 1;
                r += 1;
            }
        }
        return l;
    }
};
