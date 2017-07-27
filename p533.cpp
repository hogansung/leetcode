class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        int n = picture.size();
        int m = picture[0].size();
        
        unordered_map<string, vector<int>> um;
        vector<string> vs(n, "");
        vector<int> rsum(n, 0);
        vector<int> csum(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vs[i].push_back(picture[i][j]);
                um[vs[i]].push_back(i);
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
                    rsum[i] == N and csum[j] == N and
                    um[vs[i]].size() == N) {
                    cnt += 1;
                }
            }
        }
        return cnt;
    }
};
