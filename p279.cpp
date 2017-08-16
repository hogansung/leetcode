class Solution {
public:
    int dp(int t, vector<int>& vct, vector<int>& rcd) {
        if (t == 0) {
            return 0;
        } else if (rcd[t] != -1) {
            return rcd[t];
        } else {
            int mmin = INT_MAX;
            for (auto val : vct) {
                if (t >= val) {
                    int ret = dp(t - val, vct, rcd) + 1;
                    mmin = min(mmin, ret);
                }
            }
            return rcd[t] = mmin;
        }
    }
    
    int numSquares(int n) {
        vector<int> vct;
        for (long long i = 1; i * i <= n; i++) {
            vct.push_back(i*i);
        }
        
        vector<int> rcd(n+1, -1);
        int ret = dp(n, vct, rcd);
        return ret;
    }
};
