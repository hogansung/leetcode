class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        bool suc = true;
        { // row-wise
            for (int i = 0; i < n; i++) {
                vector<bool> used(n, false);
                for (int j = 0; j < n; j++) {
                    if (board[i][j] == '.') {
                        // do nothing
                    } else if (used[board[i][j]-'1'] == true) {
                        suc = false;
                    } else {
                        used[board[i][j]-'1'] = true;
                    }
                }
            }
        }
        { // column-wise
            for (int j = 0; j < n; j++) {
                vector<bool> used(n, false);
                for (int i = 0; i < n; i++) {
                    if (board[i][j] == '.') {
                        // do nothing
                    } else if (used[board[i][j]-'1'] == true) {
                        suc = false;
                    } else {
                        used[board[i][j]-'1'] = true;
                    }
                }
            }
        }
        { // block-wise
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    vector<bool> used(n, false);
                    for (int ii = 0; ii < 3; ii++) {
                        for (int jj = 0; jj < 3; jj++) {
                            if (board[3*i+ii][3*j+jj] == '.') {
                                // do nothing
                            } else if (used[board[3*i+ii][3*j+jj]-'1'] == true) {
                                suc = false;
                            } else {
                                used[board[3*i+ii][3*j+jj]-'1'] = true;
                            }
                        }
                    }
                }
            }
        }
        return suc;
    }
};
