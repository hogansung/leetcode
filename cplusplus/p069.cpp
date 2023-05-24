class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int r = INT_MAX;
        while (l < r) {
            long long m = (l + r) / 2 + 1;
            long long val = m * m;
            if (val > x) {
                r = m - 1;
            } else {
                l = m;
            }
        }
        return l;
    }
};
