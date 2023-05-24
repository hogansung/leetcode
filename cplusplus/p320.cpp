class Solution {
public:
    void dfs(vector<string>& ret, string str,
             const string& word, int t, const int len) {
        if (t == len) {
            ret.emplace_back(str);
        } else {
            for (int i = t; i < len; i++) {
                if (i == t) {
                    dfs(ret, str + string(1, word[i]), word, i+1, len);
                } else {
                    dfs(ret, str + to_string(i-t) + string(1, word[i]), word, i+1, len);
                }
            }
            dfs(ret, str + to_string(len-t), word, len, len);
        }
    }
    
    vector<string> generateAbbreviations(string word) {
        int len = word.length();
        vector<string> ret;
        dfs(ret, "", word, 0, len);
        return ret;
    }
};
