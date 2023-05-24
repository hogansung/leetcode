class Solution {
public:
    bool isPerfectSquare(int num) {
        long long l = 1;
        long long r = 65536;
        while (l < r) {
            long long m = (l + r) / 2;
            if (m * m  < num) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l * l == num;
    }
};
