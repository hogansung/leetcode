class Solution {
public:
    bool isPowerOfTwo(int n) {
        int cnt = 0;
        for (int i = 0; i < 32; i++) {
            cnt += n % 2;
            n /= 2;
        }
        return cnt == 1;
    }
};
