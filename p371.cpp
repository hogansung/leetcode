class Solution {
public:
    int getSum(int a, int b) {
        int ret = 0;
        bool b_c = false;
        unsigned t = 1;
        for (int i = 0; i < 32; i++) {
            bool b_a = (a&t) != 0;
            bool b_b = (b&t) != 0;
            if (b_a and b_b and b_c) {
                ret |= t;
                b_c = true;
            } else if ((b_a and b_b) or
                       (b_b and b_c) or
                       (b_c and b_a)) {
                b_c = true;
            } else if (b_a or b_b or b_c) {
                ret |= t;
                b_c = false;
            } else {
                // do nothing
            }
            t <<= 1;
        }
        return ret;
    }
};
