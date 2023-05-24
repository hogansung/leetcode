class Solution {
public:
    void splitStr(vector<string>& vct, const string& str) {
        stringstream ss(str);
        string sstr;
        while (getline(ss, sstr, ' ')) {
            vct.emplace_back(sstr);
        }
    }
    
    bool wordPattern(string pattern, string str) {
        int len_p = pattern.length();
        
        vector<string> vct;
        splitStr(vct, str);
        int len_s = vct.size();
        
        if (len_p != len_s) {
            return false;
        } else {
            unordered_map<char,string> um;
            unordered_set<string> us;
            for (int i = 0; i < len_p; i++) {
                if (um.find(pattern[i]) == um.end()) {
                    if (us.find(vct[i]) == us.end()) {
                        um[pattern[i]] = vct[i];
                        us.emplace(vct[i]);
                    } else {
                        return false;
                    }
                } else {
                    if (um[pattern[i]] != vct[i]) {
                        return false;
                    }
                }
            }
            return true;
        }
    }
};
