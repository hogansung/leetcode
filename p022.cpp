class Solution {
public:
    void dfs(vector<string>& vct, string& str, int rl, int ul) {
        if (rl == 0 and ul == 0) {
            vct.emplace_back(str);
            return;
        } else {
            if (rl > 0) {
                str.push_back('(');
                dfs(vct, str, rl-1, ul+1);
                str.pop_back();
            }
            if (ul > 0) {
                str.push_back(')');
                dfs(vct, str, rl, ul-1);
                str.pop_back();
            }
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> vct;
        string str;
        dfs(vct, str, n, 0);
        return vct;
    }
};
