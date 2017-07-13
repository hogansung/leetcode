class Solution {
public:
    const int mul = 29;
    const int mod = 1000000007;
    vector<long long> val;
    
    void dfs(vector<vector<string>>& ret, vector<string>& vct,
             const string s, int t, const int len,
             vector<long long>& dsum, vector<long long>& rsum) {
        if (t == len) {
            ret.emplace_back(vct);
        } else {
            for (int i = t+1; i <= len; i++) {
                int dval = (dsum[i] - dsum[t] + mod) % mod * val[len-i] % mod;
                int rval = (rsum[t] - rsum[i] + mod) % mod * val[t] % mod;
                if (dval == rval) {
                    vct.push_back(s.substr(t, i-t));
                    dfs(ret, vct, s, i, len, dsum, rsum);
                    vct.pop_back();
                }
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        int len = s.length();
        
        val.push_back(1);
        for (int i = 1; i < len; i++) {
            val.push_back(val[i-1] * mul % mod);
        }
        
        vector<long long> dsum(len+1, 0);
        vector<long long> rsum(len+1, 0);
        for (int i = 0; i < len; i++) {
            dsum[i+1] = (dsum[i] + val[i] * (s[i] - 'a')) % mod;
            rsum[len-1-i] = (rsum[len-i] + val[i] * (s[len-1-i] - 'a')) % mod;
        }
        
        vector<vector<string>> ret;
        vector<string> vct;
        dfs(ret, vct, s, 0, len, dsum, rsum);
        return ret;
    }
};
