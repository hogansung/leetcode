class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        
        int n = nums.size();
        int ret = 0;
        for (int i = 0; i < n; i+=2) {
            ret += min(nums[i], nums[i+1]);
        }
        return ret;
    }
};
