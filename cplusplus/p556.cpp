class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        int len = str.length();
        
        int idx = -1;
        for (int i = 0; i < len-1; i++) {
            if (str[i] < str[i+1]) {
                idx = i;
            }
        }
        
        if (idx == -1) {
            return -1;
        } else {
            vector<int> cnt(10, 0);
            for (int i = idx; i < len; i++) {
                cnt[str[i]-'0'] += 1;
            }
            
            string nstr = str.substr(0, idx);
            for (int i = str[idx]-'0'+1; i < 10; i++) {
                if (cnt[i] > 0) {
                    nstr.push_back('0' + i);
                    cnt[i] -= 1;
                    break;
                }
            }
            for (int i = 0; i < 10; i++) {
                while (cnt[i] > 0) {
                    nstr.push_back('0' + i);
                    cnt[i] -= 1;
                }
            }
            
            long long ret = strtoll(nstr.c_str(), 0, 10);
            if (ret > INT_MAX) {
                return -1;
            } else {
                return ret;
            }
        }
    }
};
