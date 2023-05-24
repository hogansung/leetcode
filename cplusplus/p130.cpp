class Solution {
public:
    bool bfs(const vector<vector<char>>& board, 
             vector<vector<bool>>& vis, const int n, const int m,
             vector<vector<int>>& dir, int r, int c) {
        bool suc = false;
        
        queue<pair<int,int>> qp;
        qp.emplace(r, c);
        while (qp.size()) {
            auto p = qp.front(); qp.pop();
            for (int i = 0; i < 4; i++) {
                int nr = p.first + dir[i][0];
                int nc = p.second + dir[i][1];
                if (nr < 0 or nr == n or nc < 0 or nc == m) {
                    suc = true;
                } else if (board[nr][nc] == 'O' and vis[nr][nc] == false) {
                    vis[nr][nc] = true;
                    qp.emplace(nr, nc);
                }
            }
        }
        return suc;
    }
    
    void cover(vector<vector<char>>& board, 
               const int n, const int m,
               vector<vector<int>>& dir, int r, int c) {
        queue<pair<int,int>> qp;
        qp.emplace(r, c);
        while (qp.size()) {
            auto p = qp.front(); qp.pop();
            for (int i = 0; i < 4; i++) {
                int nr = p.first + dir[i][0];
                int nc = p.second + dir[i][1];
                if (nr < 0 or nr == n or nc < 0 or nc == m) {
                    // do nothing
                } else if (board[nr][nc] == 'O') {
                    board[nr][nc] = 'X';
                    qp.emplace(nr, nc);
                }
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();
        if (m == 0) return;
        
        vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' and vis[i][j] == false) {
                    vis[i][j] = true;
                    bool suc = bfs(board, vis, n, m, dir, i, j);
                    if (suc == false) {
                        board[i][j] = 'X';
                        cover(board, n, m, dir, i, j);
                    }
                }
            }
        }
    }
};
