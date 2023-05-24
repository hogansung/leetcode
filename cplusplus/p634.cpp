class Solution {
public:
    int mod = 1000000007;
    
    int findDerangement(int n) {
        vector<long long> r_prod(n+2, 1);
        for (int i = n; i >= 1; i--) {
            r_prod[i] = r_prod[i+1] * i % mod;
        }
        
        long long ret = 0;
        for (int i = 2; i <= n; i++) {
            long long val = r_prod[i+1] % mod;
            if (i % 2 == 0) {
                ret = (ret + val) % mod;
            } else {
                ret = (ret - val + mod) % mod;
            }
        }
        return ret;
    }
};
