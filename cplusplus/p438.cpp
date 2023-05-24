class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int len_s = s.length();
        int len_p = p.length();
        if (len_s < len_p) {
            return vector<int>();
        } else {
            vector<int> cnt(26, 0);
            for (auto c : p) {
                cnt[c-'a'] += 1;
            }
            
            int suc_cnt = 0;
            for (int i = 0; i < 26; i++) {
                if (cnt[i] == 0) {
                    suc_cnt += 1;
                }
            }

            vector<int> ret;
            for (int i = 0; i < len_s; i++) {
                if (i >= len_p) {
                    cnt[s[i-len_p]-'a'] += 1;
                    if (cnt[s[i-len_p]-'a'] == 0) {
                        suc_cnt += 1;
                    } else if (cnt[s[i-len_p]-'a'] == 1){
                        suc_cnt -= 1;
                    }
                }
                
                cnt[s[i]-'a'] -= 1;
                if (cnt[s[i]-'a'] == 0) {
                    suc_cnt += 1;
                } else if (cnt[s[i]-'a'] == -1) {
                    suc_cnt -= 1;
                }
                
                if (suc_cnt == 26) {
                    ret.push_back(i+1-len_p);
                }
            }
            return ret;
        }
    }
};
