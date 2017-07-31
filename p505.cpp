class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int n = maze.size();
        int m = maze[0].size();
        
        vector<vector<int>> block_r(n, vector<int>());
        for (int i = 0; i < n; i++) {
            block_r[i].push_back(-1);
            for (int j = 0; j < m; j++) {
                if (maze[i][j] == 1) {
                    block_r[i].push_back(j);
                }
            }
            block_r[i].push_back(m);
        }
        
        vector<vector<int>> block_c(m, vector<int>());
        for (int j = 0; j < m; j++) {
            block_c[j].push_back(-1);
            for (int i = 0; i < n; i++) {
                if (maze[i][j] == 1) {
                    block_c[j].push_back(i);
                }
            }
            block_c[j].push_back(n);
        }
        
        int sr = start[0];
        int sc = start[1];
        int er = destination[0];
        int ec = destination[1];
        
        const int INF = 100000;
        vector<vector<int>> dis(n, vector<int>(m, INF));
        
        assert(maze[sr][sc] == 0 and maze[er][ec] == 0);
        
        queue<pair<int,int>> qp;
        dis[sr][sc] = 0;
        qp.emplace(sr, sc);
        while (qp.size()) {
            auto pv = qp.front(); qp.pop();
            int r = pv.first;
            int c = pv.second;
            
            int tr = lower_bound(block_r[r].begin(), block_r[r].end(), c) - block_r[r].begin();
            { // left
                int nr = r;
                int nc = block_r[r][tr-1] + 1;
                int ndis = dis[r][c] + (c - nc);
                if (dis[nr][nc] > ndis) {
                    dis[nr][nc] = ndis;
                    qp.emplace(nr, nc);
                }
            }
            { // right
                int nr = r;
                int nc = block_r[r][tr] - 1;
                int ndis = dis[r][c] + (nc - c);
                if (dis[nr][nc] > ndis) {
                    dis[nr][nc] = ndis;
                    qp.emplace(nr, nc);
                }
            }
            
            int tc = lower_bound(block_c[c].begin(), block_c[c].end(), r) - block_c[c].begin();
            { // top
                int nr = block_c[c][tc-1] + 1;
                int nc = c;
                int ndis = dis[r][c] + (r - nr);
                if (dis[nr][nc] > ndis) {
                    dis[nr][nc] = ndis;
                    qp.emplace(nr, nc);
                }
            }
            { // bot
                int nr = block_c[c][tc] - 1;
                int nc = c;
                int ndis = dis[r][c] + (nr - r);
                if (dis[nr][nc] > ndis) {
                    dis[nr][nc] = ndis;
                    qp.emplace(nr, nc);
                }
            }
        }
        
        if (dis[er][ec] == INF) {
            return -1;
        } else {
            return dis[er][ec];
        }
    }
};
