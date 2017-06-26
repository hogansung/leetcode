class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 0) {
            return string("");
        } else {
            string ret;
            for (int idx = 0; ; idx++) {
                if (idx == strs[0].length()) {
                    return ret;
                }
                
                for (int i = 0; i < n; i++) {
                    if (idx == strs[i].length()) {
                        return ret;
                    } else if (strs[i][idx] != strs[0][idx]) {
                        return ret;
                    }
                }
                ret.push_back(strs[0][idx]);
            }
            assert(false);
        }
    }
};
