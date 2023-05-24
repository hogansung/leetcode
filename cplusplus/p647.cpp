class Solution {
public:
    int countSubstrings(string s) {
        int len = s.length();
        int cnt = 0;
        
        // odd
        for (int i = 0; i < len; i++) {
            for (int j = 0; j <= min(i, len-1-i); j++) {
                if (s[i-j] == s[i+j]) {
                    cnt += 1;
                } else {
                    break;
                }
            }
        }
        
        // even
        for (int i = 0; i < len; i++) {
            for (int j = 0; j <= min(i, len-1-(i+1)); j++) {
                if (s[i-j] == s[i+1+j]) {
                    cnt += 1;
                } else {
                    break;
                }
            }
        }
        
        return cnt;
    }
};
