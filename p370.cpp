class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<pair<int,int>> updatePair;
        
        for (auto update : updates) {
            int l = update[0];
            int r = update[1];
            int v = update[2];
            updatePair.emplace_back(l, +v);
            updatePair.emplace_back(r+1, -v);
        }
        
        int n = updatePair.size();
        sort(updatePair.begin(), updatePair.end());
        
        vector<int> ret(length, 0);
        int sum = 0;
        int flag = 0;
        for (int i = 0; i < length; i++) {
            while (flag < n and updatePair[flag].first <= i) {
                sum += updatePair[flag].second;
                flag += 1;
            }
            ret[i] = sum;
        }
        return ret;
    }
};
