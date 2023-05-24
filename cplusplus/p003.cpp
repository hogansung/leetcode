class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        
        vector<bool> vct(256, false);
        int mmax = 0;
        int l = 0;
        int r = 0;
        while (l < len) {
            while (r < len and vct[s[r]] == false) {
                vct[s[r]] = true;
                r += 1;
            }
            mmax = max(mmax, r-l);
            vct[s[l]] = false;
            l += 1;
        }
        return mmax;
    }
};
