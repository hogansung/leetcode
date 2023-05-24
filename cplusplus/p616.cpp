class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        int len_s = s.length();
        
        vector<long long> mul(len_s, 1);
        const long long mod = 1000000007;
        for (int i = 1; i < len_s; i++) {
            mul[i] = mul[i-1] * 257 % mod;
        }
        
        vector<long long> sum(len_s+1, 0);
        for (int i = 0; i < len_s; i++) {
            sum[i+1] = (sum[i] + mul[i] * s[i]) % mod;
        }
        
        vector<bool> cover(len_s, false);
        for (auto str : dict) {
            int len = str.length();
            long long val = 0;
            for (int i = 0; i < len; i++) {
                val = (val + mul[i] * str[i]) % mod;
            }
            
            for (int i = 0; i <= len_s - len; i++) {
                int s_val = (sum[i+len] - sum[i] + mod) % mod;
                int m_val = val * mul[i] % mod;
                if (s_val == m_val) {
                    for (int j = 0; j < len; j++) {
                        cover[i+j] = true;
                    }
                }
            }
        }
        
        string ret;
        string tmp;
        for (int i = 0; i < len_s; i++) {
            if (cover[i] == true) {
                tmp.push_back(s[i]);
            } else {
                if (tmp.length() > 0) {
                    ret += "<b>";
                    ret += tmp;
                    ret += "</b>";
                    tmp = "";
                }
                ret.push_back(s[i]);
            }
        }

        if (tmp.length() > 0) {
            ret += "<b>";
            ret += tmp;
            ret += "</b>";
        }
        return ret;
    }
};
