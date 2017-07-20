class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> dictionary) {
        um = unordered_map<string,unordered_set<string>>();
        for (auto word : dictionary) {
            um[transform(word)].emplace(word);
        }
    }
    
    string transform(string s) {
        int len = s.length();
        if (len <= 2) {
            return s;
        } else {
            return string(1, s.front()) + to_string(len-2) + string(1, s.back());
        }
    }
    
    bool isUnique(string word) {
        return um[transform(word)].size() == 0 or
               (um[transform(word)].size() == 1 and um[transform(word)].count(word) == 1);
    }
    
    unordered_map<string,unordered_set<string>> um;
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */
