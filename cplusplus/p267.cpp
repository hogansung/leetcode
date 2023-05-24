class Solution {
public:
    void dfs(vector<string>& ret, string& str,
             vector<int>& cnt, int idx, int len) {
        if (str.length() == len / 2) {
            string rstr = str;
            reverse(rstr.begin(), rstr.end());
            if (idx == -1) {
                ret.emplace_back(str + rstr);
            } else {
                ret.emplace_back(str + string(1, idx) + rstr);
            }
        } else {
            for (int i = 0; i < 256; i++) {
                if (cnt[i] >= 2) {
                    cnt[i] -= 2;
                    str.push_back(i);
                    dfs(ret, str, cnt, idx, len);
                    cnt[i] += 2;
                    str.pop_back();
                }
            }
        }
    }
    
    vector<string> generatePalindromes(string s) {
        vector<int> cnt(256, 0);
        for (auto c : s) {
            cnt[c] += 1;
        }
        
        vector<int> vct;
        for (int i = 0; i < 256; i++) {
            if (cnt[i] % 2 == 1) {
                vct.push_back(i);
            }
        }
        
        vector<string> ret;
        if (vct.size() > 1) {
            return ret;
        } else {
            string str;
            dfs(ret, str, cnt, vct.size() == 0 ?-1 :vct[0], s.length());
            return ret;
        }
    }
};
