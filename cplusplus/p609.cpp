class Solution {
public:
    void split(vector<string>& vct, string& path) {
        string str;
        for (auto c : path) {
            if (c == ' ' or c == '(' or c == ')') {
                if (str.length() > 0) {
                    vct.emplace_back(str);
                    str = "";
                } 
            } else {
                str.push_back(c);
            }
        }
        assert(str.length() == 0);
    }
    
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> um;
        for (auto path : paths) {
            vector<string> vct;
            split(vct, path);
            
            int n = vct.size();
            for (int i = 1; i < n; i+=2) {
                um[vct[i+1]].emplace_back(vct[0] + "/" + vct[i]);
            }
        }
        
        vector<vector<string>> ret;
        for (auto p : um) {
            if (p.second.size() > 1) {
                ret.emplace_back(p.second);
            }
        }
        return ret;
    }
};
