class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) {
            return 0;
        } else {
            int k = 1;
            
            vector<vector<int>> rcd(k+2, vector<int>(2, INT_MIN));
            rcd[0][0] = 0;
            rcd[0][1] = -prices[0];
            for (int i = 1; i < n; i++) {
                rcd[i % (k+2)][0] = max(rcd[(i-1) % (k+2)][0], rcd[(i-1) % (k+2)][1] + prices[i]);
                rcd[i % (k+2)][1] = max(rcd[(i-1) % (k+2)][1], -prices[i]);

                if (i >= 2) {
                    rcd[i % (k+2)][1] = max(rcd[i % (k+2)][1], rcd[(i-2) % (k+2)][0] - prices[i]);
                }
            }
            return rcd[(n-1) % (k+2)][0];
        }
    }
};
