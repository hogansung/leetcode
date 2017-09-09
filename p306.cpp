class Solution {
public:
    string add(string sa, string sb) {
        reverse(sa.begin(), sa.end());
        reverse(sb.begin(), sb.end());
        
        int la = sa.length();
        int lb = sb.length();
        int carry = 0;
        
        string sc;
        int lc = 0;
        for (int lc = 0; lc < la or lc < lb or carry; lc++) {
            if (lc < la) {
                carry += sa[lc] - '0';
            }
            if (lc < lb) {
                carry += sb[lc] - '0';
            }
            sc.push_back(carry % 10 + '0');
            carry /= 10;
        }
        reverse(sc.begin(), sc.end());
        return sc;
    }
    
    bool dfs(string& sa, string& sb, int cnt,
             int t, const int len, string& num) {
        if (t == len) {
            return cnt >= 3;
        } else {
            string sc = add(sa, sb);
            int lc = sc.length();

            bool suc = t + lc <= len;
            for (int i = 0; i < lc and suc; i++) {
                suc &= (sc[i] == num[t+i]);
            }

            if (suc == true) {
                suc &= dfs(sb, sc, cnt+1, t+lc, len, num);
            }
            return suc;
        }
    }
    
    bool isAdditiveNumber(string num) {
        int len = num.length();
        bool suc = false;
        for (int i = 0; i < len; i++) {
            for (int j = i+1; j < len; j++) {
                string sa = num.substr(0, i+1);
                string sb = num.substr(i+1, j-i);
                if ((sa.length() > 1 and sa[0] == '0') or 
                    (sb.length() > 1 and sb[0] == '0')) {
                    // illegal
                } else {
                    suc |= dfs(sa, sb, 2, j+1, len, num);
                }
            }
        }
        return suc;
    }
};
