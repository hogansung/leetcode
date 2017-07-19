class Solution {
public:
    bool transform(vector<int>& vct, string& abbr) {
        int len = abbr.length();
        string str;
        for (auto c : abbr) {
            if (c >= 'a' and c <= 'z') {
                if (str.length() > 0) {
                    vct.push_back(strtol(str.c_str(), 0, 10));
                    str = "";
                }
                vct.push_back(-(c - 'a'));
            } else if (c == '0' and str == "") {
                return false;
            } else {
                str.push_back(c);
            }
        }
        if (str.length() > 0) {
            vct.push_back(strtol(str.c_str(), 0, 10));
            str = "";
        }
        return true;
    }
    
    bool validWordAbbreviation(string word, string abbr) {
        vector<int> vct;
        bool suc = transform(vct, abbr);
        if (suc == false) {
            return false;
        }
        
        int len = word.length();
        int flag_w = 0;
        for (auto v : vct) {
            if (v <= 0) {
                if (flag_w >= len or word[flag_w]-'a' + v != 0) {
                    return false;
                }
                flag_w += 1;
            } else {
                flag_w += v;
            }
            printf("%d %d\n", flag_w, v);
        }
        printf("zz2");
        return flag_w == len;
    }
};
