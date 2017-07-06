class Solution {
public:
    bool checkVowel(char c) {
        return (c == 'a' or c == 'A' or
                c == 'e' or c == 'E' or
                c == 'i' or c == 'I' or
                c == 'o' or c == 'O' or
                c == 'u' or c == 'U');
    }
    
    string reverseVowels(string s) {
        int len = s.length();
        string vowel;
        for (int i = 0; i < len; i++) {
            if (checkVowel(s[i]) == true) {
                vowel.push_back(s[i]);
            }
        }
        reverse(vowel.begin(), vowel.end());
        
        int t = 0;
        for (int i = 0; i < len; i++) {
            if (checkVowel(s[i]) == true) {
                s[i] = vowel[t];
                t += 1;
            }
        }
        return s;
    }
};
