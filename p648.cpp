class Solution {
public:
    const int mod = 1000000007;
    const int mul = 29;
    
    void split(vector<string>& vct, string& sentence) {
        stringstream ss(sentence);
        string str;
        while (getline(ss, str, ' ')) {
            vct.emplace_back(str);
        }
    }
    
    string replaceWords(vector<string>& dict, string sentence) {
        vector<long long> val(1000, 1);
        for (int i = 1; i < 1000; i++) {
            val[i] = val[i-1] * mul % mod;
        }
        
        int n = dict.size();
        vector<vector<long long>> rootVct(n, vector<long long>(1, 0));
        for (int i = 0; i < n; i++) {
            int len = dict[i].length();
            for (int j = 0; j < len; j++) {
                rootVct[i].push_back((rootVct[i].back() + (dict[i][j] - 'a') * val[j]) % mod);
            }
        }
        
        vector<string> vct;
        split(vct, sentence);
        
        unordered_map<string, string> um;
        int m = vct.size();
        for (int i = 0; i < m; i++) {
            int len = vct[i].length();
            
            vector<long long> suc(1, 0);
            for (int j = 0; j < len; j++) {
                suc.push_back((suc.back() + (vct[i][j] - 'a') * val[j]) % mod);
            }
            
            int best_len = INT_MAX;
            int best_idx = -1;
            for (int j = 0; j < n; j++) {
                int len = rootVct[j].size();
                if (suc.size() >= len and
                    suc[len-1] == rootVct[j].back()) {
                    if (len-1 < best_len) {
                        best_len = len - 1;
                        best_idx = j;
                    }
                }
            }
            
            if (best_idx == -1) {
                um[vct[i]] = vct[i];
            } else {
                um[vct[i]] = dict[best_idx];
            }
        }
        
        string ret = um[vct[0]];
        for (int i = 1; i < m; i++) {
            ret += " ";
            ret += um[vct[i]];
        }
        return ret;
    }
};
