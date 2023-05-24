class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0 or k == 0) {
            return 0;
        } else {
            vector<vector<int>> rcd(2, vector<int>(2, 0));
            rcd[0][0] = k;
            rcd[0][1] = 0;
            for (int i = 1; i < n; i++) {
                rcd[i%2][0] = rcd[(i-1)%2][0] * (k-1) + rcd[(i-1)%2][1] * (k-1);
                rcd[i%2][1] = rcd[(i-1)%2][0] * 1 + rcd[(i-1)%2][1] * 0;
            }
            return rcd[(n-1)%2][0] + rcd[(n-1)%2][1];
        }
    }
};
