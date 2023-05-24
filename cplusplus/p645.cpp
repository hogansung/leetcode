class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(n, 0);
        for (int i = 0; i < n; i++) {
            cnt[nums[i]-1] += 1;
        }
        
        int num0 = -1;
        int num2 = -1;
        for (int i = 0; i < n; i++) {
            if (cnt[i] == 0) {
                num0 = i+1;
            } else if (cnt[i] == 2) {
                num2 = i+1;
            }
        }
        
        vector<int> ret = {num2, num0};
        return ret;
    }
};
