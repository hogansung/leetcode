class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n == 0) return false;
        int m = matrix[0].size();
        if (m == 0) return false;
        
        int r = n - 1;
        int c = 0;
        while (r >= 0 and c < m) {
            if (target < matrix[r][c]) {
                r -= 1;
            } else if (target > matrix[r][c]) {
                c += 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
