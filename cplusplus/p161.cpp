class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int len_s = s.length();
        int len_t = t.length();
        if (len_s == len_t) {
            int cnt = 0;
            for (int i = 0; i < len_s; i++) {
                if (s[i] != t[i]) {
                    cnt += 1;
                }
            }
            return cnt == 1;
        } else if (abs(len_s - len_t) == 1) {
            bool skip = false;
            int flag_s = 0;
            int flag_t = 0;
            while (flag_s < len_s and flag_t < len_t) {
                if (s[flag_s] != t[flag_t]) {
                    if (skip == false) {
                        skip = true;
                        if (len_s < len_t) {
                            flag_t += 1;
                        } else {
                            flag_s += 1;
                        }
                    } else {
                        return false;
                    }
                } else {
                    flag_s += 1;
                    flag_t += 1;
                }
            }
            return true;
        } else {
            return false;
        }
    }
};
