class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        if (k == 0) { // special case: check nearby 0s
            for (int i = 0; i < n-1; i++) {
                if (nums[i] == 0 and nums[i+1] == 0) {
                    return true;
                }
            }
            return false;
        } else {
            unordered_map<int, int> um;
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (um.find(sum % k) == um.end()) {
                    um[sum % k] = i;
                }
                
                sum += nums[i];
                
                if (um.find(sum % k) != um.end() and
                    i - um[sum % k] + 1 >= 2) {
                    return true;
                }
            }
            return false;
        }
    }
};
