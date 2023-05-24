class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int n = nums.size();
        if (n == 0) return nums;
        int m = nums[0].size();
        if (m == 0) return nums;
        if (n * m != r * c) return nums;
        
        vector<vector<int>> ret(r, vector<int>(c, 0));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int val = i * c + j;
                ret[i][j] = nums[val / m][val % m];
            }
        }
        return ret;
    }
};
