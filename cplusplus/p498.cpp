class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return vector<int>();
        int m = matrix[0].size();
        if (m == 0) return vector<int>();
        
        vector<vector<int>> vct(n+m-1, vector<int>());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vct[i+j].push_back(matrix[i][j]);
            }
        }
        
        vector<int> ret;
        for (int i = 0; i < n+m-1; i++) {
            if (i % 2 == 0) {
                reverse(vct[i].begin(), vct[i].end());
            }
            for (auto v : vct[i]) {
                ret.push_back(v);
            }
        }
        return ret;
    }
};
