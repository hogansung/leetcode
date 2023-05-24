class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        vector<int> tab(256, 0);
        int len = s.length();
        
        int l = 0;
        int cnt = 0;
        int mmax = 0;
        for (int r = 0; r < len; r++) {
            if (tab[s[r]] == 0) {
                cnt += 1;
            }
            tab[s[r]] += 1;
            
            while (cnt == 3) {
                tab[s[l]] -= 1;
                if (tab[s[l]] == 0) {
                    cnt -= 1;
                }
                l += 1;
            }
            mmax = max(mmax, r - l + 1);
        }
        return mmax;
    }
};
