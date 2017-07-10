class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if (ops.size() == 0) {
            return m * n;
        } else {
            vector<vector<int>> vct(m, vector<int>());
            for (auto op : ops) {
                for (int i = 0; i < op[0]; i++) {
                    vct[i].push_back(op[1]);
                }
            }

            int ret = 0;
            for (int i = 0; i < m; i++) {
                sort(vct[i].begin(), vct[i].end());
                if (vct[i].size() == vct[0].size()) {
                    ret += vct[i][0];
                }
            }
            return ret;
        }
    }
};
