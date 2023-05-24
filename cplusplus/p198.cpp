class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        vector<vector<int>> rcd(2, vector<int>(2, 0));
        rcd[0][1] = nums[0];
        for (int i = 1; i < n; i++) {
            rcd[i%2][0] = max(rcd[(i-1)%2][0], rcd[(i-1)%2][1]);
            rcd[i%2][1] = rcd[(i-1)%2][0] + nums[i];
        }
        return max(rcd[(n-1)%2][0], rcd[(n-1)%2][1]);
    }
};
