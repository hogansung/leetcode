class Solution {
public:
    const int NUM_ROUND = 30;
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ret;
        int n = nums.size();
        if (n == 0) {
            return ret;
        } else {
            unordered_set<int> us;
            for (int i = 0; i < NUM_ROUND; i++) {
                int t = rand() % n;

                int sum = 0;
                for (auto num : nums) {
                    if (num == nums[t]) {
                        sum += 1;
                    }
                }
                if (sum > n/3) {
                    us.emplace(nums[t]);
                }
            }

            for (auto val : us) {
                ret.push_back(val);
            }
            return ret;
        }  
    }
};
