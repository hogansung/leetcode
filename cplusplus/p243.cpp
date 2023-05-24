class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int n = words.size();
        unordered_map<string, vector<int>> um;
        for (int i = 0; i < n; i++) {
            um[words[i]].push_back(i);
        }
        
        vector<int> vct1 = um[word1];
        vector<int> vct2 = um[word2];
        int n1 = vct1.size();
        int n2 = vct2.size();
        int f1 = 0;
        int f2 = 0;
        int mmin = INT_MAX;
        while (f1 < n1 and f2 < n2) {
            mmin = min(mmin, abs(vct2[f2] - vct1[f1]));
            if (vct1[f1] < vct2[f2]) {
                f1 += 1;
            } else {
                f2 += 1;
            }
        }
        return mmin;
    }
};
