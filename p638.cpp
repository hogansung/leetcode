class Solution {
public:
    const int mul = 7;
    
    int hash(vector<int>& vct) {
        int st = 0;
        for (auto v : vct) {
            st *= mul;
            st += v;
        }
        return st;
    }
    
    int dp(vector<vector<int>>& special, vector<int>& needs,
           vector<int>& rcd, const int n, const int m) {
        
        int hv = hash(needs);
        if (hv == 0) {
            return 0;
        } else if (rcd[hv] != INT_MAX) {
            return rcd[hv];
        } else {
            int mmin = INT_MAX;
            for (int i = 0; i < m; i++) {
                bool suc = true;
                for (int j = 0; j < n; j++) {
                    suc &= (needs[j] >= special[i][j]);
                }
                
                if (suc == false) {
                    continue;
                } else {   
                    for (int j = 0; j < n; j++) {
                        needs[j] -= special[i][j];
                    }
                    
                    mmin = min(mmin, dp(special, needs, rcd, n, m) + special[i][n]);
                    
                    for (int j = 0; j < n; j++) {
                        needs[j] += special[i][j];
                    }
                }
            }
            return rcd[hv] = mmin;
        }
    }
    
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = price.size();
        for (int i = 0; i < n; i++) {
            vector<int> vct(n+1, 0);
            vct[i] = 1;
            vct[n] = price[i];
            special.emplace_back(vct);
        }
        
        int m = special.size();
        vector<int> rcd(117649, INT_MAX);
        int ret = dp(special, needs, rcd, n, m);
        return ret;
    }
};
