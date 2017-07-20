class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int n = rooms.size();
        if (n == 0) return;
        int m = rooms[0].size();
        if (m == 0) return;
        
        queue<pair<int,int>> qp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (rooms[i][j] == 0) {
                    qp.emplace(i, j);
                }
            }
        }
        
        vector<vector<int>> dir{{0,1}, {0,-1}, {1,0}, {-1,0}};
        while (qp.size()) {
            auto pv = qp.front(); qp.pop();
            int r = pv.first;
            int c = pv.second;
            for (int i = 0; i < 4; i++) {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if (nr < 0 or nr == n or nc < 0 or nc == m) {
                    // do nothing
                } else if (rooms[nr][nc] == INT_MAX) {
                    rooms[nr][nc] = rooms[r][c] + 1;
                    qp.emplace(nr, nc);
                }
            }
        }
    }
};
