class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int len = s.length();
        unordered_map<string, int> um;
        for (int i = 0; i <= len-10; i++) {
            um[s.substr(i,10)] += 1;
        }
        
        vector<string> ret;
        for (auto p : um) {
            if (p.second >= 2) {
                ret.emplace_back(p.first);
            }
        }
        return ret;
    }
};
