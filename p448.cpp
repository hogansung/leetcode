class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for (auto num : nums) {
            int idx = abs(num);
            if (nums[idx-1] > 0) {
                nums[idx-1] *= -1;
            }
        }
        
        vector<int> ret;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                ret.push_back(i+1);
            }
        }
        return ret;
    }
};
