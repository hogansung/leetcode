class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1 = num1.length();
        reverse(num1.begin(), num1.end());
        
        int len2 = num2.length();
        reverse(num2.begin(), num2.end());
        
        int cry = 0;
        string ret;
        for (int i = 0; (i < len1 or i < len2) or cry; i++) {
            if (i < len1) {
                cry += num1[i] - '0';
            }
            if (i < len2) {
                cry += num2[i] - '0';
            }
            ret.push_back('0' + cry % 10);
            cry /= 10;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
