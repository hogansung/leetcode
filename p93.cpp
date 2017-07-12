class Solution {
public:
    void dfs(vector<string>& ret, vector<int>& vct,
             int t, const string& s, const int len) {
        if (t == len or vct.size() == 4) {
            if (t == len and vct.size() == 4) {
                string str = to_string(vct[0]);
                for (int i = 1; i < 4; i++) {
                    str += ".";
                    str += to_string(vct[i]);
                }
                ret.emplace_back(str);
            } else {
                // do nothing
            }
        } else {
            if (s[t] == '0') {
                vct.push_back(0);
                dfs(ret, vct, t+1, s, len);
                vct.pop_back();
            } else {
                for (int i = 0; i < 3 and t+i < len; i++) {
                    int val = strtol(s.substr(t, i+1).c_str(), 0, 10);
                    if (val <= 255) {
                        vct.push_back(val);
                        dfs(ret, vct, t+i+1, s, len);
                        vct.pop_back();
                    }
                }
            }
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        int len = s.length();
        vector<string> ret;
        vector<int> vct;
        dfs(ret, vct, 0, s, len);
        return ret;
    }
};
