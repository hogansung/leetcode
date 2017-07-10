class Solution {
public:
    string reverseWords(string s) {
        string ret;
        string tmp;
        for (char c : s) {
            if (c == ' ') {
                reverse(tmp.begin(), tmp.end());
                ret += tmp;
                tmp = "";
                ret.push_back(c);
            } else {
                tmp.push_back(c);
            }
        }
        reverse(tmp.begin(), tmp.end());
        ret += tmp;
        return ret;
    }
};
