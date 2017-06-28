class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) {
            return vector<vector<int>>();
        } else {
            vector<vector<int>> vct;
            { // i = 0
                vector<int> row(1, 1);
                vct.emplace_back(row);
            }
            for (int i = 1; i < numRows; i++) {
                vector<int> row;
                row.emplace_back(1);
                for (int j = 0; j < i-1; j++) {
                    row.emplace_back(vct[i-1][j] + vct[i-1][j+1]);
                }
                row.emplace_back(1);
                vct.emplace_back(row);
            }
            return vct;
        }
    }
};
