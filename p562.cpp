class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        int n = M.size();
        if (n == 0) return 0;
        int m = M[0].size();
        if (m == 0) return 0;
        
        int mmax = 0;
        { // row-wise
            for (int i = 0; i < n; i++) {
                int cnt = 0;
                for (int j = 0; j < m; j++) {
                    if (M[i][j] == 1) {
                        cnt += 1;
                    } else {
                        mmax = max(mmax, cnt);
                        cnt = 0;
                    }
                    mmax = max(mmax, cnt);
                }
            }
        }
        
        { // col-wise
            for (int j = 0; j < m; j++) {
                int cnt = 0;
                for (int i = 0; i < n; i++) {
                    if (M[i][j] == 1) {
                        cnt += 1;
                    } else {
                        mmax = max(mmax, cnt);
                        cnt = 0;
                    }
                    mmax = max(mmax, cnt);
                }
            }
        }
        
        { // slash-wise
            for (int i = n-1; i >= 0; i--) {
                int cnt = 0;
                for (int j = 0; j < min(m, n-i); j++) {
                    if (M[i+j][j] == 1) {
                        cnt += 1;
                    } else {
                        mmax = max(mmax, cnt);
                        cnt = 0;
                    }
                    mmax = max(mmax, cnt);
                }
            }
            for (int j = 0; j < m; j++) {
                int cnt = 0;
                for (int i = 0; i < min(n, m-j); i++) {
                    if (M[i][i+j] == 1) {
                        cnt += 1;
                    } else {
                        mmax = max(mmax, cnt);
                        cnt = 0;
                    }
                    mmax = max(mmax, cnt);
                }
            }
        }
        
        { // backslash-wise
            for (int j = 0; j < m; j++) {
                int cnt = 0;
                for (int i = 0; i < min(j+1, n); i++) {
                    if (M[i][j-i] == 1) {
                        cnt += 1;
                    } else {
                        mmax = max(mmax, cnt);
                        cnt = 0;
                    }
                    mmax = max(mmax, cnt);
                }
            }
            for (int i = 0; i < n; i++) {
                int cnt = 0;
                for (int j = 0; j < min(m, n-i); j++) {
                    if (M[i+j][n-1-j] == 1) {
                        cnt += 1;
                    } else {
                        mmax = max(mmax, cnt);
                        cnt = 0;
                    }
                    mmax = max(mmax, cnt);
                }
            }
        }
        return mmax;
    }
};
