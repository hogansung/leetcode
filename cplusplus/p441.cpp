class Solution {
public:
    int arrangeCoins(int n) {
        int l = 0;
        int r = 65536;
        while (l < r) {
            long long m = (l + r) / 2 + 1;
            if (m * (m+1) / 2 > n) {
                r = m - 1;
            } else {
                l = m;
            }
        }
        return l;
    }
};
