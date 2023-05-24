class Solution {
public:
    string convertToBase7(int num) {
        bool sign = false;
        if (num < 0) {
            sign = true;
            num = -num;
        }
        
        string str;
        while (num) {
            str.push_back('0'+num%7);
            num /= 7;
        }
        
        if (str.length() == 0) {
            str.push_back('0');
        }
        
        if (sign == true) {
            str.push_back('-');
        }
        
        reverse(str.begin(), str.end());
        return str;
    }
};
