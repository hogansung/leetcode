class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ret;        
        for (int i = 0; i < n; i++) {
            if (i > 0 and nums[i] == nums[i-1]) {
                continue;
            } else {
                int l = i+1;
                int r = n-1;
                
                while (l < r) {
                    if (l-1 > i and nums[l] == nums[l-1]) {
                        l += 1;
                        continue;
                    } else if (r+1 < n and nums[r] == nums[r+1]) {
                        r -= 1;
                        continue;
                    } else if (nums[i] + nums[l] + nums[r] < 0) {
                        l += 1;
                    } else if (nums[i] + nums[l] + nums[r] > 0) {
                        r -= 1;
                    } else {
                        vector<int> tmp {nums[i], nums[l], nums[r]};
                        ret.emplace_back(tmp);
                        l += 1;
                    }
                }
            }
        }
        return ret;
    }
};
