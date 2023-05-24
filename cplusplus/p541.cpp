class Solution {
public:
    string reverseStr(string s, int k) {
        int len = s.length();
        for (int i = 0; i < len; i+=2*k) {
            int slen = min(len-i, k);
            for (int j = 0; j < slen/2; j++) {
                swap(s[i+j], s[i+slen-1-j]);
            }
        }
        return s;
    }
};
