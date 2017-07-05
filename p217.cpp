class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> us;
        for (int i = 0; i < n; i++) {
            if (us.find(nums[i]) == us.end()) {
                us.emplace(nums[i]);
            } else {
                return true;
            }
        }
        return false;
    }
};
