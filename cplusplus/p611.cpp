class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                int k = lower_bound(nums.begin() + j+1, nums.end(), nums[i]+nums[j]) - nums.begin() - 1;
                sum += k - j;
            }
        }
        return sum;
    }
};
