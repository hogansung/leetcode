class Solution {
public:
    string sortString(string str) {
        sort(str.begin(), str.end());
        return str;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string,vector<string>> um;
        for (int i = 0; i < n; i++) {
            um[sortString(strs[i])].emplace_back(strs[i]);
        }
        
        vector<vector<string>> ret;
        for (auto pp : um) {
            ret.emplace_back(pp.second);
        }
        return ret;
    }
};
