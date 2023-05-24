class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.length();
        vector<bool> vis(len+1, false);
        vis[0] = true;
        
        for (int i = 0; i < len; i++) {
            if (vis[i] == true) {
                for (auto word : wordDict) {
                    if (i + word.length() <= len and
                        s.substr(i, word.length()) == word) {
                        vis[i + word.length()] = true;
                    }
                }
            }
        }
        return vis[len];
    }
};
