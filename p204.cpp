class Solution {
public:
    int countPrimes(int n) {
        vector<bool> vis(n+1, false);
        for (int i = 2; i <= sqrt(n); i++) {
            if (vis[i] == false) {
                for (int j = i*i; j <= n; j+=i) {
                    vis[j] = true;
                }
            }
        }
        
        int cnt = 0;
        for (int i = 2; i < n; i++) {
            if (vis[i] == false) {
                cnt += 1;
            }
        }
        return cnt;
    }
};
