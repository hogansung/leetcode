class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int max_iter = 20;
        for (int i = 0; i < max_iter; i++) {
            int idx = rand() % n;
            int cnt = 0;
			for (int j = 0; j < n; j++) {
                if (nums[j] == nums[idx]) {
                    cnt += 1;
                }
            }
            if (cnt > n/2) {
                return nums[idx];
            }
        }
        assert(false);
    }
};
