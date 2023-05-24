
class Solution {
public:
    void dfs(int t, vector<vector<int>>& M, 
            const int n, vector<bool>& vis) {
        vis[t] = true;
        for (int i = 0; i < n; i++) {
            if (M[t][i] == 1 and vis[i] == false) {
                dfs(i, M, n, vis);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        vector<bool> vis(n, false);
        
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i] == false) {
                dfs(i, M, n, vis);
                cnt += 1; 
            }
        }
        return cnt;
    }
};
