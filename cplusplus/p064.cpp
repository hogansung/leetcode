class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        
        int m = grid[0].size();
        if (m == 0) return 0;
        
        vector<vector<int>> rcd(2, vector<int>(m, 0));
        rcd[0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i > 0 or j > 0) {
	                rcd[i%2][j] = INT_MAX;
            	}
                if (j > 0) {
                    rcd[i%2][j] = min(rcd[i%2][j], rcd[i%2][j-1]);
                }
                if (i > 0) {
                    rcd[i%2][j] = min(rcd[i%2][j], rcd[(i-1)%2][j]);
                }
                rcd[i%2][j] += grid[i][j];
            }
        }
        return rcd[(n-1)%2][m-1];
    }
};
