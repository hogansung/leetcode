class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        if (m == 0) return 0;

        vector<vector<int>> rsum(n, vector<int>(m+1, 0));
        vector<vector<int>> rvct(n, vector<int>());
        for (int i = 0; i < n; i++) {
            rvct[i].push_back(-1);
            for (int j = 0; j < m; j++) {
                rsum[i][j+1] = rsum[i][j] + (grid[i][j] == 'E');
                if (grid[i][j] == 'W') {
                    rvct[i].push_back(j);
                }
            }
            rvct[i].push_back(m);
        }
        
        vector<vector<int>> csum(m, vector<int>(n+1, 0));
        vector<vector<int>> cvct(m, vector<int>());
        for (int j = 0; j < m; j++) {
            cvct[j].push_back(-1);
            for (int i = 0; i < n; i++) {
                csum[j][i+1] = csum[j][i] + (grid[i][j] == 'E');
                if (grid[i][j] == 'W') {
                    cvct[j].push_back(i);
                }
            }
            cvct[j].push_back(n);
        }

        int mmax = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '0') {
                    int r_idx = lower_bound(rvct[i].begin(), rvct[i].end(), j) - rvct[i].begin();
                    int c_idx = lower_bound(cvct[j].begin(), cvct[j].end(), i) - cvct[j].begin();

                    int val = 0;
                    val += rsum[i][rvct[i][r_idx]] - rsum[i][rvct[i][r_idx-1]+1];
                    val += csum[j][cvct[j][c_idx]] - csum[j][cvct[j][c_idx-1]+1];
                    mmax = max(mmax, val);
                }
            }
        }
        return mmax;
    }
};
