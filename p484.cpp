class Solution {
public:
    vector<int> findPermutation(string s) {
        int len = s.length();
        vector<bool> used(len+1, false); // 0-base
        
        vector<pair<char,int>> vct;
        char sign = s[0];
        int cnt = 0;
        for (auto c : s) {
            if (c == sign) {
                cnt += 1;
            } else {
                vct.emplace_back(sign, cnt);
                sign = c;
                cnt = 1;
            }
        }
        vct.emplace_back(sign, cnt);
        
        vector<int> ret;
        int flag = 0;
        
        for (auto p : vct) {
            if (p.first == 'I') {
                if (ret.size() == 0) {
                    for (int i = 0; i < p.second; i++) {
                        ret.push_back(flag + i + 1);
                    }
                    flag += p.second; 
                } else {
                    for (int i = 0; i < p.second-1; i++) {
                        ret.push_back(flag + i + 1);
                    }
                    flag += p.second - 1;  
                }
            } else {
                for (int i = p.second; i >= 0; i--) {
                    ret.push_back(flag + i + 1);
                }
                flag += p.second + 1;
            }
        }
        
        if (vct.back().first == 'I') {
            ret.push_back(flag + 1);
        }
        return ret;
    }
};
