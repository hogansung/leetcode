class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> vct{"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        vector<unordered_set<char>> vus(3, unordered_set<char>());
        for (int i = 0; i < 3; i++) {
            for (auto c : vct[i]) {
                vus[i].emplace(c);
            }
        }
        
        vector<string> ret;
        int n = words.size();
        for (int i = 0; i < n; i++) {
            int len = words[i].length();
            bool suc = false;
            for (int k = 0; k < 3; k++) {
                bool ssuc = true;
                for (int j = 0; j < len and ssuc; j++) {
                    char c = (words[i][j] >= 'a' and words[i][j] <= 'z') ?words[i][j] :words[i][j]-'A'+'a';
                    if (vus[k].find(c) == vus[k].end()) {
                        ssuc = false;
                    }
                }
                if (ssuc) {
                    suc = true;
                }
            }
            if (suc == true) {
                ret.emplace_back(words[i]);
            }
        }
        return ret;
    }
};
