class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        sort(nums.rbegin(), nums.rend());
        
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i-1]) {
                cnt += 1;
                if (cnt == 3) {
                    return nums[i];
                }
            }
        }
        return nums[0];
    }
};
