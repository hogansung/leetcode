class Solution {
public:
    int countSegments(string s) {
        int len = s.length();
        int ret = 0;
        int cnt = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == ' ') {
                if (cnt > 0) {
                    cnt = 0;
                    ret += 1;
                }
            } else {
                cnt += 1;
            }
        }
        if (cnt > 0) {
            ret += 1;
        }
        return ret;
    }
};
