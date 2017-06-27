class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        string str;
        vector<string> vct;
        for (int i = 0; i < len; i++) {
            if (s[i] == ' ') {
                if (str.length() != 0) {
                    vct.emplace_back(str);
                    str = "";
                }
            } else {
                str.push_back(s[i]);
            }
        }
        
        if (str.length() != 0) {
            vct.emplace_back(str);
        }
        
        if (vct.size() == 0) {
            return 0;
        } else {
            return vct.back().length();
        }
    }
};
