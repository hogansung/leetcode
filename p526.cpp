class Solution {
public:
    int calHash(vector<bool>& used, const int N) {
        int val = 0;
        for (int i = 0; i < N; i++) {
            val <<= 1;
            val + used[i];
        }
        return val;
    }
    
    int dp(int t, const int N, vector<bool>&used, 
           vector<vector<int>>& rcd) {
        int hash = calHash(used, N);
        if (t == N) {
            return 1;
        } else if (rcd[t][hash] != -1) {
            return rcd[t][hash];
        } else {
            int sum = 0;
            for (int i = 1; i <= N; i++) {
                if (used[i] == false and 
                    ((t+1) % i == 0 or i % (t+1) == 0)) {
                    used[i] = true;
                    sum += dp(t+1, N, used, rcd);
                    used[i] = false;
                }
            }
            return sum;
        }
    }
    
    int countArrangement(int N) {
        vector<vector<int>> rcd(15, vector<int>(1 << N, -1));
        vector<bool> used(N, false);
        return dp(0, N, used, rcd);
    }
};
