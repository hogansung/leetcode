class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int rb = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        
        vector<int> ret;
        if (lb == rb) {
            ret.push_back(-1);
            ret.push_back(-1);
        } else {
            ret.push_back(lb);
            ret.push_back(rb-1);
        }
        return ret;
    }
};
