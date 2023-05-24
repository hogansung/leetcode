class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len_s = s.length();
        int len_t = t.length();
        if (len_s != len_t) return false;
        
        unordered_map<char,char> um;
        unordered_set<char> us;
        for (int i = 0; i < len_s; i++) {
            if (um.find(s[i]) == um.end()) {
                if (us.find(t[i]) == us.end()) {
                    um[s[i]] = t[i];
                    us.emplace(t[i]);
                } else {
                    return false;
                }
            } else {
                if (um[s[i]] != t[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};
