class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.length();
        int len2 = num2.length();
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        vector<int> vct(len1+len2-1, 0);
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                int d1 = num1[i]-'0';
                int d2 = num2[j]-'0';
                vct[i+j] += d1 * d2;
            }
        }
        
        int val = 0;
        for (int i = 0; i < len1+len2-1 or val; i++) {
            if (i < len1+len2-1) {
                val += vct[i];
                vct[i] = val % 10;
            } else {
                vct.push_back(val % 10);
            }
            val /= 10;
        }
        
        while (vct.size() > 1 and vct.back() == 0) {
            vct.pop_back();
        }
        
        string ret;
        for (auto v : vct) {
            ret.push_back(v+'0');
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
