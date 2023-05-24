class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        
        vector<pair<int,int>> vmax(n, pair<int,int>(INT_MIN,-1));
        for (int i = 1; i < n; i++) {
            if (vmax[i-1].first < nums[i-1]) {
                vmax[i].first = nums[i-1];
                vmax[i].second = i-1;
            } else {
                vmax[i] = vmax[i-1];
            }
        }
        
        vector<pair<int,int>> vmin(n, pair<int,int>(INT_MAX,-1));
        for (int i = n-2; i >= 0; i--) {
            if (vmin[i+1].first > nums[i+1]) {
                vmin[i].first = nums[i+1];
                vmin[i].second = i+1;
            } else {
                vmin[i] = vmin[i+1];
            }
        }
        
        int l = INT_MAX;
        int r = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (vmin[i].first < nums[i]) {
                l = min(l, i);
                r = max(r, vmin[i].second);
            }
            if (vmax[i].first > nums[i]) {
                l = min(l, vmax[i].second);
                r = max(r, i);
            }
        }
        
        if (l == INT_MAX) {
            return 0;
        } else {
            return r - l + 1;
        }
    }
};
