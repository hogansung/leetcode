class Solution {
public:
    int dp(int l, int r, string& s,
           vector<vector<int>>& rcd) {
        if (l > r) {
            return 0;
        } else if (l == r) {
            return 1;
        } else if (rcd[l][r] != -1) {
            return rcd[l][r];
        } else {
            int mmax = 0;
            mmax = max(mmax, dp(l+1, r, s, rcd));
            mmax = max(mmax, dp(l, r-1, s, rcd));
            if (s[l] == s[r]) {
                mmax = max(mmax, dp(l+1, r-1, s, rcd) + 2);
            }
            return rcd[l][r] = mmax;
        }
    }
    
    int longestPalindromeSubseq(string s) {
        int len = s.length();
        vector<vector<int>> rcd(len, vector<int>(len, -1));
        return dp(0, len-1, s, rcd);
    }
};
