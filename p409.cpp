class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> cnt(52, 0);
        for (char c : s) {
            if (c >= 'a' and c <= 'z') {
                cnt[c-'a'] += 1;
            } else {
                cnt[c-'A'+26] += 1;
            }
        }
        
        bool odd = false;
        int sum = 0;
        for (int i = 0; i < 52; i++) {
            sum += cnt[i] / 2 * 2;
            if (cnt[i] % 2 == 1) {
                odd = true;
            }
        }
        if (odd == true) {
            sum += 1;
        }
        return sum;
    }
};
