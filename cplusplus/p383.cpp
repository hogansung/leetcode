class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> vct(26, 0);
        for (char c : magazine) {
            vct[c-'a'] += 1;
        }
        for (char c : ransomNote) {
            if (vct[c-'a'] == 0) {
                return false;
            } else {
                vct[c-'a'] -= 1;
            }
        }
        return true;
    }
};
