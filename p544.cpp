class Solution {
public:
    string findContestMatch(int n) {
        vector<string> vct;
        for (int i = 0; i < n; i++) {
            vct.emplace_back(to_string(i+1));
        }
        
        while (vct.size() > 1) {
            int size = vct.size();
            vector<string> nvct;
            for (int i = 0; i < size/2; i++) {
                nvct.emplace_back("(" + vct[i] + "," + vct[size-1-i] + ")");
            }
            vct = nvct;
        }
        return vct[0];
    }
};
