class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                if (nums[i] + nums[l] + nums[r] < target) {
                    sum += r - l;
                    l += 1;
                } else {
                    r -= 1;
                }
            }
        }
        return sum;
    }
};
