class Solution {
public:
    int climbStairs(int n) {
        vector<int> vct(n+1, 0);
        vct[1] = 1;
        vct[2] = 2;
        for (int i = 3; i <= n; i++) {
            vct[i] = vct[i-2] + vct[i-1];
        }
        return vct[n];
    }
};
