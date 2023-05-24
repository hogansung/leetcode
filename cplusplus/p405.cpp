class Solution {
public:
    string toHex(int num) {
        if (num == 0) {
            return "0";
        } else {
            unsigned unum = num;
            string ret;
            while (unum) {
                int val = unum % 16;
                if (val < 10) {
                    ret.push_back('0' + val);
                } else {
                    ret.push_back('a' + val - 10);a
                }
                unum /= 16;
            }
            reverse(ret.begin(), ret.end());
            return ret;
        }
    }
};
