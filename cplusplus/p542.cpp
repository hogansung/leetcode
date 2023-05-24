class Solution {
public:
    const int INF = INT_MAX;
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> dis(n, vector<int>(m, INF));
        queue<pair<int,int>> qv;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    qv.emplace(i, j);
                    dis[i][j] = 0;
                }
            }
        }
        
        vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while (qv.size()) {
            auto pv = qv.front(); qv.pop();
            int r = pv.first;
            int c = pv.second;
            for (int i = 0; i < 4; i++) {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if (nr >= 0 and nr < n and
                    nc >= 0 and nc < m and 
                    dis[nr][nc] == INF) {
                    qv.emplace(nr, nc);
                    dis[nr][nc] = dis[r][c] + 1;
                }
            }
        }
        return dis;
    }
};
