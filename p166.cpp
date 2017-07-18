class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        bool sign = false;
        long long nval = numerator;
        if (nval < 0) {
            nval = -nval;
            sign ^= true;
        }
        
        long long dval = denominator;
        if (dval < 0) {
            dval = -dval;
            sign ^= true;
        }
        
        string ret;
        if (nval > 0 and sign == true) {
            ret.push_back('-');
        }
        ret += to_string(nval / dval);
        nval %= dval;
        
        unordered_map<int,int> um;
        vector<int> vct;
        int idx = -1;
        while (nval) {
            if (um.find(nval) == um.end()) {
                um[nval] = vct.size();
                nval *= 10;
                int val = nval / dval;
                nval %= dval;
                vct.push_back(val);
            } else {
                idx = um[nval];
                break;
            }
        }
        
        int n = vct.size();
        if (idx == -1) {
            if (n > 0) {
                ret.push_back('.');
                for (auto v : vct) {
                    ret.push_back('0' + v);
                }
            }
        } else {
            ret.push_back('.');
            for (int i = 0; i < idx; i++) {
                ret.push_back('0' + vct[i]);
            }
            ret.push_back('(');
            for (int i = idx; i < n; i++) {
                ret.push_back('0' + vct[i]);
            }
            ret.push_back(')');
        }
        return ret;
    }
};
