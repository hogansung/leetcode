class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> tmp(m, 0);
        for (int i = 0; i < m; i++) {
            tmp[i] = nums1[i];
        }
        
        int idx_1 = 0;
        int idx_2 = 0;
        while (idx_1 < m and idx_2 < n) {
            if (tmp[idx_1] < nums2[idx_2]) {
                nums1[idx_1+idx_2] = tmp[idx_1];
                idx_1 += 1;
            } else {
                nums1[idx_1+idx_2] = nums2[idx_2];
                idx_2 += 1;
            }
        }
        
        while (idx_1 < m) {
            nums1[idx_1+idx_2] = tmp[idx_1];
            idx_1 += 1;
        }
        while (idx_2 < n) {
            nums1[idx_1+idx_2] = nums2[idx_2];
            idx_2 += 1;
        }
    }
};
