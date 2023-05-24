class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();
        if (m == 0) return;
        
        vector<vector<int>> dir = {{0,1},{0,-1},{1,1},{1,0},{1,-1},{-1,1},{-1,0},{-1,-1}};
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                int cnt = 0;
                for (int i = 0; i < 8; i++) {
                    int nr = r + dir[i][0];
                    int nc = c + dir[i][1];
                    if (nr >= 0 and nr < n and
                        nc >= 0 and nc < m and
                        (board[nr][nc] & 1) == 1) {
                        cnt += 1;
                    }
                }
                
                if ((board[r][c] == 1 and cnt >= 2 and cnt <= 3) or
                    (board[r][c] == 0 and cnt == 3)) {
                    board[r][c] |= (1 << 1);        
                }
            }
        }
        
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                board[r][c] >>= 1;
            }
        }
    }
};
