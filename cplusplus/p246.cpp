class Solution {
public:
    bool isStrobogrammatic(string num) {
        int len = num.length();
        for (int i = 0; i < len/2; i++) {
            if (num[i] == '0' and num[len-1-i] != '0') {
                return false;
            } else if (num[i] == '1' and num[len-1-i] != '1') {
                return false;
            } else if (num[i] == '2') {
                return false;
            } else if (num[i] == '3') {
                return false;
            } else if (num[i] == '4') {
                return false;
            } else if (num[i] == '5') {
                return false;
            } else if (num[i] == '6' and num[len-1-i] != '9') {
                return false;
            } else if (num[i] == '7') {
                return false;
            } else if (num[i] == '8' and num[len-1-i] != '8') {
                return false;
            } else if (num[i] == '9' and num[len-1-i] != '6') {
                return false;
            }
        }
        if (len % 2 == 1) {
            if (num[len/2] == '0' or num[len/2] == '1' or num[len/2] == '8') {
                return true;
            } else {
                return false;
            }
        }
        return true;
    }
};
