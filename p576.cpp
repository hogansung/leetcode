class Solution {
public:
    const int mod = 1000000007;
    
    int dp(int r, int c, int t, 
           const int m, const int n,
           vector<vector<vector<int>>>& rcd, 
           vector<vector<int>>& dir) {
        if (r < 0 or r >= m or c < 0 or c >= n) {
            return 1;
        } else if (t == 0) {
            return 0;
        } else if (rcd[t][r][c] != -1) {
            return rcd[t][r][c];
        } else {
            long long sum = 0;
            for (int i = 0; i < 4; i++) {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                sum += dp(nr, nc, t-1, m, n, rcd, dir);
            }
            return rcd[t][r][c] = sum % mod;
        }
    }
    
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<int>>> rcd(N+1, vector<vector<int>>(m, vector<int>(n, -1)));
        vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        return dp(i, j, N, m, n, rcd, dir);
    }
};
