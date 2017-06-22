#include <algorithm>

class Solution {
public:
    int reverse(int x) {
        bool sign = false;
        if (x < 0) {
            sign = true;
            x *= -1;
        }
        
        string str = to_string(x);
        std::reverse(str.begin(), str.end());
        
        long long rx = strtoll(str.c_str(), 0, 10);
        if (sign) {
            rx *= -1;
        }
        
        if (rx > INT_MAX or rx < INT_MIN) {
            return 0;
        } else {
            return rx;
        }
    }
};
