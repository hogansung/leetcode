class Solution {
public:
    int firstUniqChar(string s) {
        int len = s.length();
        vector<int> vct(26, 0);
        for (int i = 0; i < len; i++) {
            vct[s[i]-'a'] += 1;
        }
        for (int i = 0; i < len; i++) {
            if (vct[s[i]-'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};
