class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> cnt(256, 0);
        for (auto c : s) {
            cnt[c] += 1;
        }
        
        int oddNum = 0;
        for (int i = 0; i < 256; i++) {
            if (cnt[i]%2 == 1) {
                oddNum += 1;
            }
        }
        return oddNum <= 1;
    }
};
