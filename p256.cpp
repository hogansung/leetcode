class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        if (n == 0) {
            return 0;
        } else {
            vector<vector<int>> rcd(2, vector<int>(3, 0));

            rcd[0] = costs[0];
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < 3; j++) {
                    rcd[i%2][j] = INT_MAX;
                    for (int k = 0; k < 3; k++) {
                        if (j == k) {
                            // do nothing
                        } else {
                            rcd[i%2][j] = min(rcd[i%2][j], rcd[(i-1)%2][k] + costs[i][j]);
                        }
                    }
                }
            }
            
            int mmin = INT_MAX;
            for (int j = 0; j < 3; j++) {
                mmin = min(mmin, rcd[(n-1)%2][j]);
            }
            return mmin;
        }
    }
};
