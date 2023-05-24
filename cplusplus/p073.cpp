class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return;
        int m = matrix[0].size();
        if (m == 0) return;
        
        // special case: first row
        bool f_row = false;
        for (int j = 0; j < m; j++) {
            if (matrix[0][j] == 0) {
                f_row = true;
            }
        }
        
        // special case: first column
        bool f_col = false;
        for (int i = 0; i < n; i++) {
            if (matrix[i][0] == 0) {
                f_col = true;
            }
        }
        
        // general case: other rows and columns
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }
        
        // deal with general case: row
        for (int i = 1; i < n; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < m; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // deal with general case: column
        for (int j = 1; j < m; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < n; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // deal with special case: first row
        if (f_row == true) {
            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }
        
        // deal with special case: first column
        if (f_col == true) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
