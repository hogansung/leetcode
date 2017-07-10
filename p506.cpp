class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> cnums = nums;
        sort(cnums.rbegin(), cnums.rend());
        
        unordered_map<int,int> um;
        for (int i = 0; i < n; i++) {
            um[cnums[i]] = i+1;
        }
        
        vector<string> ret;
        for (int i = 0; i < n; i++) {
            if (um[nums[i]] == 1) {
                ret.emplace_back("Gold Medal");
            } else if (um[nums[i]] == 2) {
                ret.emplace_back("Silver Medal");
            } else if (um[nums[i]] == 3) {
                ret.emplace_back("Bronze Medal");
            } else {
                ret.emplace_back(to_string(um[nums[i]]));
            }
        }
        return ret;
    }
};
