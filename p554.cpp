class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();
        
        int sum = 0;
        for (auto val : wall[0]) {
            sum += val;
        }
        
        unordered_map<int,int> um;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (auto val : wall[i]) {
                sum += val;
                um[sum] += 1;
            }
        }
        
        int mmin = n;
        for (auto p : um) {
            if (p.first < sum) {
                mmin = min(mmin, n - p.second);
            }
        }
        return mmin;
    }
};
