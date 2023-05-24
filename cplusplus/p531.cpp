class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int n = picture.size();
        int m = picture[0].size();
        
        vector<int> rsum(n, 0);
        vector<int> csum(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (picture[i][j] == 'B') {
                    rsum[i] += 1;
                    csum[j] += 1;
                }
            }
        }
        
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (picture[i][j] == 'B' and 
                    rsum[i] == 1 and csum[j] == 1) {
                    cnt += 1;
                }
            }
        }
        return cnt;
    }
};
