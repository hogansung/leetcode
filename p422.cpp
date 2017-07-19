class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int n = words.size();
        for (int i = 0; i < n; i++) {
            int len = words[i].length();
            for (int j = 0; j < len; j++) {
                if (i >= words[j].length() or 
                    j >= n or 
                    words[i][j] != words[j][i]) {
                    return false;
                }
            }
        }
        return true;
    }
};
