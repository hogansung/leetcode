class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int n = board.size();
        int m = board[0].size();
        
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        } else {
            vector<vector<int>> dir = {{1,-1},{1,0},{1,1},{0,-1},{0,1},{-1,-1},{-1,0},{-1,1}};
            vector<vector<bool>> vis(n, vector<bool>(m, false));
            queue<pair<int,int>> q;

            q.emplace(click[0], click[1]);
            vis[click[0]][click[1]] = true;
            while (q.size()) {
                auto p = q.front(); q.pop();
                int r = p.first;
                int c = p.second;
                
                int cnt = 0;
                for (int i = 0; i < 8; i++) {
                    int nr = r + dir[i][0];
                    int nc = c + dir[i][1];
                    if (nr >= 0 and nr < n and
                        nc >= 0 and nc < m and
                        board[nr][nc] == 'M') {
                        cnt += 1;
                    }
                }
                
                if (cnt == 0) {
                    board[r][c] = 'B';
                    for (int i = 0; i < 8; i++) {
                        int nr = r + dir[i][0];
                        int nc = c + dir[i][1];
                        if (nr >= 0 and nr < n and
                            nc >= 0 and nc < m and
                            board[nr][nc] == 'E' and
                            vis[nr][nc] == false) {
                            q.emplace(nr, nc);
                            vis[nr][nc] = true;
                        }
                    }
                } else {
                    board[r][c] = '0' + cnt;
                }
            }
            return board;
        }
    }
};
