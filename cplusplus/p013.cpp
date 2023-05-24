class Solution {
public:
    int romanToInt(string s) {
        int len = s.length();
        int sum = 0;
        for (int i = 0; i < len; i++) {
            if (i < len-1 and s[i] == 'I' and s[i+1] == 'V') {
                sum += 4;
                i += 1;
            } else if (i < len-1 and s[i] == 'I' and s[i+1] == 'X') {
                sum += 9;
                i += 1;
            } else if (i < len-1 and s[i] == 'X' and s[i+1] == 'L') {
                sum += 40;
                i += 1;
            } else if (i < len-1 and s[i] == 'X' and s[i+1] == 'C') {
                sum += 90;
                i += 1;
            } else if (i < len-1 and s[i] == 'C' and s[i+1] == 'D') {
                sum += 400;
                i += 1;
            } else if (i < len-1 and s[i] == 'C' and s[i+1] == 'M') {
                sum += 900;
                i += 1;
            } else if (s[i] == 'I') {
                sum += 1;
            } else if (s[i] == 'V') {
                sum += 5;
            } else if (s[i] == 'X') {
                sum += 10;
            } else if (s[i] == 'L') {
                sum += 50;
            } else if (s[i] == 'C') {
                sum += 100;
            } else if (s[i] == 'D') {
                sum += 500;
            } else if (s[i] == 'M') {
                sum += 1000;
            } else {
                assert(false);
            }
        }
        return sum;
    }
};
