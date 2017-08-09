class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> um;
        
        int mmax = 0;
        int sum = 0;
        um[sum] = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (um.find(sum) == um.end()) {
                um[sum] = i+1;
            }
            
            if (um.find(sum - k) != um.end()) {
                mmax = max(mmax, i+1 - um[sum-k]);
            }
        }
        return mmax;
    }
};
