class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> vct(2, vector<int>());
        { // i = 0
            vector<int> row(1, 1);
            vct[0] = row;
        }
        for (int i = 1; i <= rowIndex; i++) {
            vector<int> row;
            row.emplace_back(1);
            for (int j = 0; j < i-1; j++) {
                row.emplace_back(vct[(i-1)%2][j] + vct[(i-1)%2][j+1]);
            }
            row.emplace_back(1);
            vct[i%2] = row;
        }
        return vct[rowIndex%2];
    }
};
