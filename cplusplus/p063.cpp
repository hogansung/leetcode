class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // use (m, n), same as previous question
        int m = obstacleGrid.size();
        if (m == 0) return 0;
        
        int n = obstacleGrid[0].size();
        if (n == 0) return 0;
        
        vector<vector<int>> rcd(2, vector<int>(n, 0));
        rcd[0][0] = obstacleGrid[0][0] == 0 ?1 :0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0 or j > 0) {
                    rcd[i%2][j] = 0;
                }
                if (obstacleGrid[i][j] == 0) {
                    if (j > 0) {
                        rcd[i%2][j] += rcd[i%2][j-1];
                    }
                    if (i > 0) {
                        rcd[i%2][j] += rcd[(i-1)%2][j];
                    }
                }
            }
        }
        return rcd[(m-1)%2][n-1];
    }
};
