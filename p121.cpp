class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) {
            return 0;
        }
        
        vector<int> vmin = vector<int>(n, INT_MAX);
        vector<int> vmax = vector<int>(n, INT_MIN);
        
        { // vmin
            vmin[0] = min(vmin[0], prices[0]);
            for (int i = 1; i < n; i++) {
                vmin[i] = min(vmin[i-1], prices[i]);
            }
        }
        { // vmax
            vmax[n-1] = max(vmax[n-1], prices[n-1]);
            for (int i = n-2; i >= 0; i--) {
                vmax[i] = max(vmax[i+1], prices[i]);
            }
        }
        
        int mmax = 0;
        for (int i = 0; i < n-1; i++) {
            mmax = max(mmax, vmax[i+1] - vmin[i]);
        }
        return mmax;
    }
};
