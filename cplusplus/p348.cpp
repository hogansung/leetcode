class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        tbl = vector<vector<int>>(n, vector<int>(n, 0));
        rn = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        tbl[row][col] = player;
        
        { // row-wise
            bool suc = true;
            for (int j = 0; j < rn; j++) {
                if (tbl[row][j] != player) {
                    suc = false;
                }
            }
            if (suc == true) {
                return player;
            }
        }
        
        { // col-wise
            bool suc = true;
            for (int i = 0; i < rn; i++) {
                if (tbl[i][col] != player) {
                    suc = false;
                }
            }
            if (suc == true) {
                return player;
            }
        }
        
        if (row == col) { // slash
            bool suc = true;
            for (int i = 0; i < rn; i++) {
                if (tbl[i][i] != player) {
                    suc = false;
                }
            }
            if (suc == true) {
                return player;
            }
        }
        
        if (row + col == rn-1) { // backslash
            bool suc = true;
            for (int i = 0; i < rn; i++) {
                if (tbl[i][rn-1-i] != player) {
                    suc = false;
                }
            }
            if (suc == true) {
                return player;
            }
        }
        
        return 0;
    }
    
    vector<vector<int>> tbl;
    int rn;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
