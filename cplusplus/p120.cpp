class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> rcd(2, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i+1; j++) {
                if (j == 0) {
                    rcd[(i+1)%2][j] = rcd[i%2][j] + triangle[i][j];
                } else if (j == i) {
                    rcd[(i+1)%2][j] = rcd[i%2][j-1] + triangle[i][j];
                } else {
                    rcd[(i+1)%2][j] = min(rcd[i%2][j-1], rcd[i%2][j]) + triangle[i][j];
                }
            }
        }
        
        int mmin = INT_MAX;
        for (int i = 0; i < n; i++) {
            mmin = min(mmin, rcd[n%2][i]);
        }
        return mmin;
    }
};
