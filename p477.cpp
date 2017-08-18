class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<vector<int>> cnt(32, vector<int>(2, 0));
        for (auto num : nums) {
            for (int i = 0; i < 32; i++) {
                if (num % 2 == 0) {
                    cnt[i][0] += 1;
                } else {
                    cnt[i][1] += 1;
                }
                num >>= 1;
            }
        }
        
        int sum = 0;
        for (int i = 0; i < 32; i++) {
            sum += cnt[i][0] * cnt[i][1];
        }
        return sum;
    }
};
