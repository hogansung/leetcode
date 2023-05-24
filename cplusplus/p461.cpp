class Solution {
public:
    int hammingDistance(int x, int y) {
        int cnt = 0;
        for (int i = 0; i < 31; i++) {
            int val = (1 << i);
            if ((x&val) != (y&val)) {
                cnt += 1;
            }
        }
        return cnt;
    }
};
