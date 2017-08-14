class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length();
        vector<int> cnt(26, 0);
        for (auto c : s1) {
            cnt[c-'a'] += 1;
        }
        
        int len2 = s2.length();
        vector<vector<int>> sum(26, vector<int>(len2+1, 0));
        for (int i = 0; i < len2; i++) {
            for (int j = 0; j < 26; j++) {
                sum[j][i+1] = sum[j][i];
            }
            sum[s2[i]-'a'][i+1] += 1;
        }
        
        bool suc = false;
        for (int i = 0; i <= len2-len1; i++) {
            bool ssuc = true;
            for (int j = 0; j < 26; j++) {
                ssuc &= (cnt[j] == sum[j][i+len1] - sum[j][i]);
            }
            suc |= ssuc;
        }
        return suc;
    }
};
