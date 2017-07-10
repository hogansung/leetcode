class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int i = 0; i <= sqrt(c); i++) {
            int v = i * i;
            int j = sqrt(c - v);
            if (j * j == c - v) {
                return true;
            }
        }
        return false;
    }
};
