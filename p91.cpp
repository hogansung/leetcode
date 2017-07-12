class Solution {
public:
    int dfs(int t, const string& s, const int len) {
        if (t == len) {
            return 1;
        } else if (s[t] == '0') {
            return 0;
        } else {
            int sum = 0;
            sum += dfs(t+1, s, len);
            if (t+1 < len and 
                (s[t] <= '1' or (s[t] == '2' and s[t+1] <= '6'))) {
                sum += dfs(t+2, s, len);
            }
            return sum;
        }
    }
    
    int numDecodings(string s) {
        int len = s.length();
        if (len == 0) {
            return 0;
        } else {
            return dfs(0, s, len);
        }
    }
};
