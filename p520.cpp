class Solution {
public:
    bool detectCapitalUse(string word) {
        int len = word.length();
        if (word[0] >= 'a' and word[0] <= 'z') {
            bool all_l = true;
            for (int i = 1; i < len; i++) {
                if (word[i] >= 'a' and word[i] <= 'z') {
                    // good
                } else {
                    all_l = false;
                }
            }
            return all_l;
        } else {
            bool all_l = true;
            bool all_u = true;
            for (int i = 1; i < len; i++) {
                if (word[i] >= 'a' and word[i] <= 'z') {
                    all_u = false;
                } else {
                    all_l = false;
                }
            }
            return all_l | all_u;
        }
    }
};
