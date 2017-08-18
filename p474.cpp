class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>> vct;
        for (auto str : strs) {
            int n0 = 0;
            int n1 = 0;
            for (auto c : str) {
                if (c == '0') {
                    n0 += 1;
                } else {
                    n1 += 1;
                }
            }
            vct.emplace_back(n0, n1);
        }
        
        int p = vct.size();
        vector<vector<vector<int>>> rcd(2, vector<vector<int>>(m+1, vector<int>(n+1, 0)));
        for (int k = 0; k < p; k++) {
            for (int i = 0; i <= m; i++) {
                for (int j = 0; j <= n; j++) {
                    rcd[(k+1)%2][i][j] = max(rcd[(k+1)%2][i][j], rcd[k%2][i][j]);
                    if (i >= vct[k].first and j >= vct[k].second) {
                        rcd[(k+1)%2][i-vct[k].first][j-vct[k].second] = 
                            max(rcd[k%2][i-vct[k].first][j-vct[k].second], rcd[k%2][i][j] + 1);
                    }
                }
            }
            rcd[k%2] = vector<vector<int>>(m+1, vector<int>(n+1, 0));
        }
        
        int mmax = 0;
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                mmax = max(mmax, rcd[p%2][i][j]);
            }
        }
        return mmax;
    }
};
