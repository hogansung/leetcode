class Solution {
public:
    int dfs(int t, int d, int m, int n,
            vector<bool>& vis) {
        if (d == n) {
            return 1;
        } else {
            int r = t / 3;
            int c = t % 3;
            int sum = d >= m ?1 :0;
            for (int nt = 0; nt < 9; nt++) {
                if (nt == t) {
                    continue;
                } else {
                    int nr = nt / 3;
                    int nc = nt % 3;
                    if (abs(nr-r) % 2 == 0 and 
                        abs(nc-c) % 2 == 0) {
                        int mr = (nr+r) / 2;
                        int mc = (nc+c) / 2;
                        int mt = 3 * mr + mc;
                        if (vis[mt] == true and vis[nt] == false) {
                            vis[nt] = true;
                            sum += dfs(nt, d+1, m, n, vis);
                            vis[nt] = false;
                        }
                    } else if (vis[nt] == false) {
                        vis[nt] = true;
                        sum += dfs(nt, d+1, m, n, vis);
                        vis[nt] = false;
                    }
                }
            }
            return sum;
        }
    }
    
    int numberOfPatterns(int m, int n) {
        vector<bool> vis(9, false);
        
        int sum = 0;
        for (int nt = 0; nt < 9; nt++) {
            vis[nt] = true;
            sum += dfs(nt, 1, m, n, vis);
            vis[nt] = false;
        }
        return sum;
    }
};
