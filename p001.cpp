class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        vector<pair<int,int>> vct;
        for (int i = 0; i < n; i++) {
            vct.emplace_back(nums[i], i);
        }
        sort(vct.begin(), vct.end());
        
        int l = 0;
        int r = n-1;
        while (l < r) {
            if (vct[l].first + vct[r].first < target) {
                l += 1;
            } else if (vct[l].first + vct[r].first > target) {
                r -= 1;
            } else {
                vector<int> ret = {vct[l].second, vct[r].second};
                return ret;
            }
        }
        assert(false);
    }
};
