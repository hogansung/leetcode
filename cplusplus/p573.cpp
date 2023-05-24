class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        const int INF = 100000;
        vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
        
        int tr = tree[0];
        int tc = tree[1];
        vector<vector<int>> t_dis(height, vector<int>(width, INF));
        { // BFS: find out nuts distance to tree
            queue<pair<int,int>> qp;
            t_dis[tr][tc] = 0;
            qp.emplace(tr, tc);
            while (qp.size()) {
                auto p = qp.front(); qp.pop();
                int r = p.first;
                int c = p.second;
                for (int i = 0; i < 4; i++) {
                    int nr = r + dir[i][0];
                    int nc = c + dir[i][1];
                    if (nr >= 0 and nr < height and
                        nc >= 0 and nc < width and
                        t_dis[nr][nc] == INF) {
                        t_dis[nr][nc] = t_dis[r][c] + 1;
                        qp.emplace(nr, nc);
                    }
                }
            }
        }
        
        int sr = squirrel[0];
        int sc = squirrel[1];
        vector<vector<int>> s_dis(height, vector<int>(width, INF));
        { // BFS: find out nuts distance to squirrel
            queue<pair<int,int>> qp;
            s_dis[sr][sc] = 0;
            qp.emplace(sr, sc);
            while (qp.size()) {
                auto p = qp.front(); qp.pop();
                int r = p.first;
                int c = p.second;
                for (int i = 0; i < 4; i++) {
                    int nr = r + dir[i][0];
                    int nc = c + dir[i][1];
                    if (nr >= 0 and nr < height and
                        nc >= 0 and nc < width and
                        s_dis[nr][nc] == INF) {
                        s_dis[nr][nc] = s_dis[r][c] + 1;
                        qp.emplace(nr, nc);
                    }
                }
            }
        }
        
        int sum = 0;
        for (auto nut : nuts) {
            int r = nut[0];
            int c = nut[1];
            sum += t_dis[r][c];
        }
        
        int mmin = INT_MAX;
        for (auto nut : nuts) {
            int r = nut[0];
            int c = nut[1];
            int val = 2 * sum - t_dis[r][c];
            mmin = min(mmin, val + s_dis[r][c]);
        }
        return mmin;
    }
};
