class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> ret;
        int len = s.length();
        for (int i = 0; i < len-1; i++) {
            if (s[i] == s[i+1] and s[i] == '+') {
                string str = s;
                str[i] = str[i+1] = '-';
                ret.emplace_back(str);
            }
        }
        return ret;
    }
};
