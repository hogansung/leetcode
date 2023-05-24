class Solution {
public:
    bool checkRecord(string s) {
        int len = s.length();
        int cnt_A = 0;
        int cnt_L = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == 'L') {
                if (cnt_L == 2) {
                    return false;
                }
                cnt_L += 1;
            } else {
                cnt_L = 0;
                if (s[i] == 'A') {
                    cnt_A += 1;
                }
            }
        }
        return cnt_A <= 1;
    }
};
