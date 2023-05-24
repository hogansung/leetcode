class Solution {
public:
    string longestPalindrome(string s) {
        string ns;
        int len = s.length();
        
        int mmax = 0;
        int idx;
        { // odd
            for (int i = 0; i < len; i++) {
                bool suc = true;
                for (int j = 0; i-j >= 0 and i+j < len and suc; j++) {
                    if (s[i-j] != s[i+j]) {
                        suc = false;
                    } else if (2*j+1 > mmax) {
                        mmax = 2*j+1;
                        idx = i-j;
                    }
                }
            }
        }
        { // even
            for (int i = 0; i < len; i++) {
                bool suc = true;
                for (int j = 0; i-j >= 0 and i+1+j < len and suc; j++) {
                    if (s[i-j] != s[i+1+j]) {
                        suc = false;
                    } else if (2*j+2 > mmax) {
                        mmax = 2*j+2;
                        idx = i-j;
                    }
                }
            }
        }
        return s.substr(idx, mmax);
    }
};
