class Solution {
public:
    int minSteps(int n) {
        if (n == 1) {
            return 0;
        } else {
            for (int i = 2; i <= sqrt(n); i++) {
                if (n % i == 0) {
                    return minSteps(n/i) + i;
                }
            }
            return n;
        }
    }
};
