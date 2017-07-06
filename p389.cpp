class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> vct(26, 0);
        for (char c : s) {
            vct[c-'a'] += 1;
        }
        for (char c : t) {
            vct[c-'a'] -= 1;
        }
        for (int i = 0; i < 26; i++) {
            if (vct[i] == -1) {
                return 'a' + i;
            }
        }
    }
};
