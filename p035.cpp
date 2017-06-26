class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        vector<int> nnums;
        nnums.emplace_back(INT_MIN);
        for (int num : nums) {
            nnums.emplace_back(num);
        }
        nnums.emplace_back(INT_MAX);
        
        int l = 0;
        int r = nnums.size() - 1;
        while (l < r) {
            int m = (l+r) / 2;
            if (nnums[m] < target) {
                l = m+1;
            } else {
                r = m;
            }
        }
        return l-1;
    }
};
