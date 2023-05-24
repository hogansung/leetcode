class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        string ret;
        int val = 0;
        int len_a = a.length();
        int len_b = b.length();
        for (int i = 0; i < len_a or i < len_b or val; i++) {
            if (i < len_a) {
                val += a[i] - '0';
            }
            if (i < len_b) {
                val += b[i] - '0';
            }
            ret += to_string(val % 2);
            val /= 2;
        }
        
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
