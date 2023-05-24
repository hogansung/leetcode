class Solution {
public:
    int dfs(int l, int r,
            unordered_map<int,int>& um) {
        if (l > r) {
            return 1;
        } else if (um.find(r-l) != um.end()) {
            return um[r-l];
        } else {
            int sum = 0;
            for (int i = l; i <= r; i++) {
                sum += dfs(l, i-1, um) * dfs(i+1, r, um);
            }
            return um[r-l] = sum;
        }
    }
    
    int numTrees(int n) {
        unordered_map<int,int> um;
        return dfs(1, n, um);
    }
};
