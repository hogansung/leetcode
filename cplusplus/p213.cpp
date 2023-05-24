class Solution {
public:
    int linear_rob(vector<int>& nums) {
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
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int l0;
        int l1;
        { // last house is 0
            vector<int> nnums;
            for (int i = 0; i < n-1; i++) {
                nnums.push_back(nums[i]);
            }
            l0 = linear_rob(nnums);
        }

        { // last house is 1
            vector<int> nnums;
            for (int i = 1; i < n-2; i++) {
                nnums.push_back(nums[i]);
            }
            l1 = linear_rob(nnums) + nums[n-1];
        }
        
        return max(l0, l1);
    }
};
