class Solution {
public:
    void dfs(vector<vector<char>>& grid, 
             vector<vector<int>>& dir,
             int r, int c, const int n, const int m) {
        grid[r][c] = '0';
        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            if (nr >= 0 and nr < n and
                nc >= 0 and nc < m and
                grid[nr][nc] == '1') {
                dfs(grid, dir, nr, nc, n, m);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        if (m == 0) return 0;
        
        vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
        
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, dir, i, j, n, m);
                    cnt += 1;
                }
            }
        }
        return cnt;
    }
};
