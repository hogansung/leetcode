class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        int idx = -1;
        for (int i = 0; i < n-1; i++) {
            if (nums[i] < nums[i+1]) {
                idx = i;
            }
        }
        
        if (idx == -1) { // reverse
            reverse(nums.begin(), nums.end());
        } else {
            int mmin = INT_MAX;
            int nidx;
            for (int i = idx+1; i < n; i++) {
                if (nums[i] > nums[idx] and nums[i] < mmin) {
                    nidx = i;
                    mmin = nums[i];
                }
            }
            swap(nums[idx], nums[nidx]);
            sort(nums.begin()+idx+1, nums.end());
        }
    }
};
