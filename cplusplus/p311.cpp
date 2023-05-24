class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int x = A.size();
        int z = B.size();
        int y = B[0].size();
        
        vector<vector<pair<int,int>>> vctA(x, vector<pair<int,int>>());
        for (int i = 0; i < x; i++) {
            for (int k = 0; k < z; k++) {
                if (A[i][k] != 0) {
                    vctA[i].emplace_back(k, A[i][k]);
                }
            }
        }
        
        vector<vector<pair<int,int>>> vctB(y, vector<pair<int,int>>());
        for (int k = 0; k < z; k++) {
            for (int j = 0; j < y; j++) {
                if (B[k][j] != 0) {
                    vctB[j].emplace_back(k, B[k][j]);
                }
            }
        }
        
        vector<vector<int>> ret(x, vector<int>(y, 0));
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                int nA = vctA[i].size();
                int nB = vctB[j].size();
                int fA = 0;
                int fB = 0;
                int sum = 0;
                while (fA < nA and fB < nB) {
                    if (vctA[i][fA].first < vctB[j][fB].first) {
                        fA += 1;
                    } else if (vctA[i][fA].first > vctB[j][fB].first) {
                        fB += 1;
                    } else {
                        sum += vctA[i][fA].second * vctB[j][fB].second;
                        fA += 1;
                        fB += 1;
                    }
                }
                ret[i][j] = sum;
            }
        }
        return ret;
    }
};
