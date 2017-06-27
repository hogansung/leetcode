class Solution {
public:
    void dfs(vector<string>& vct, string& str, 
        const string& digits, int pos, const int len) {
        if (pos == len) {
            vct.emplace_back(str);
            return;
        } else {
            if (digits[pos] == '7') {
                for (int i = 0; i < 4; i++) {
                    str.push_back('p' + i);
                    dfs(vct, str, digits, pos+1, len);
                    str.pop_back();
                }
            } else if (digits[pos] == '8') {
                for (int i = 0; i < 3; i++) {
                    str.push_back('t' + i);
                    dfs(vct, str, digits, pos+1, len);
                    str.pop_back();
                }
            } else if (digits[pos] == '9') {
                for (int i = 0; i < 4; i++) {
                    str.push_back('w' + i);
                    dfs(vct, str, digits, pos+1, len);
                    str.pop_back();
                }
            } else {
                for (int i = 0; i < 3; i++) {
                    str.push_back('a' + (digits[pos]-'2')*3 + i);
                    dfs(vct, str, digits, pos+1, len);
                    str.pop_back();
                }
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        int len = digits.length();
        if (len == 0) {
            return vector<string>();
        } else {
            vector<string> vct;
            string str;
            dfs(vct, str, digits, 0, len);
            return vct;
        }
    }
};
