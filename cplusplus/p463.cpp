class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        if (m == 0) return 0;
        
        vector<vector<int>> dir{{0,1},{0,-1},{1,0},{-1,0}};
        
        vector<int> cnt(5, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int sum = 0;
                    for (int k = 0; k < 4; k++) {
                        int r = i + dir[k][0];
                        int c = j + dir[k][1];
                        if (r < 0 or r == n or c < 0 or c == m) {
                            // do nothing
                        } else if (grid[r][c] == 1) {
                            sum += 1;
                        }
                    }
                    cnt[sum] += 1;
                }
            }
        }
        
        int ret = 0;
        for (int i = 0; i < 5; i++) {
            ret += cnt[i] * (4 - i);
        }
        return ret;
    }
};
