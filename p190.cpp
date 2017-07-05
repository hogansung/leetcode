class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string str;
        for (int i = 0; i < 32; i++) {
            str.push_back('0' + n%2);
            n /= 2;
        }
        return strtoll(str.c_str(), 0, 2);
    }
};
