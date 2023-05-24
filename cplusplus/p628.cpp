class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        
        int n = nums.size();
        return max(nums[0]*nums[1]*nums[2],
                   nums[0]*nums[n-2]*nums[n-1]);
    }
};
