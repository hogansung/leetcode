class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        if (m == 0) return 0;
        
        vector<vector<int>> vct(n, vector<int>(m, INT_MAX));
        int mmax = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '0') {
                    vct[i][j] = 0;
                } else {
                    // top
                    if (i > 0) {
                        vct[i][j] = min(vct[i][j], vct[i-1][j]);
                    } else {
                        vct[i][j] = 0;
                    }

                    // left
                    if (j > 0) {
                        vct[i][j] = min(vct[i][j], vct[i][j-1]);
                    } else {
                        vct[i][j] = 0;
                    }

                    // top-left
                    if (i > 0 and j > 0) {
                        vct[i][j] = min(vct[i][j], vct[i-1][j-1]);
                    } else {
                        vct[i][j] = 0;
                    }
                    
                    vct[i][j] += 1;
                    mmax = max(mmax, vct[i][j]);
                }
            }
        }
        return mmax * mmax;
    }
};
