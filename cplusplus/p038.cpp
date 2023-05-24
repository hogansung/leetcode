class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        for (int i = 1; i < n; i++) {
            string nstr = "";
            int len = str.length();
            int idx = 0;
            int val = str[idx] - '0';
            int cnt = 0;
            for (; idx < len; idx++) {
                if (str[idx] - '0' == val) {
                    cnt += 1;
                } else {
                    nstr += to_string(cnt);
                    nstr += to_string(val);
                    val = str[idx] - '0';
                    cnt = 1;
                }
            }
            nstr += to_string(cnt);
            nstr += to_string(val);
            str = nstr;
        }
        return str;
    }
};
