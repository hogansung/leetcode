class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_set<int> us;
        for (int i = 0; i < min(n,k+1); i++) {
            if (us.find(nums[i]) == us.end()) {
                us.emplace(nums[i]);
            } else {
                return true;
            }
        }
        for (int i = min(n,k+1); i < n; i++) {
            us.erase(us.find(nums[i-k-1]));
            if (us.find(nums[i]) == us.end()) {
                us.emplace(nums[i]);
            } else {
                return true;
            }
        }
        return false;
    }
};
