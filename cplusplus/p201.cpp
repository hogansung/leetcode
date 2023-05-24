class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int dis = n-m+1;
        int ret = 0;
        for (int i = 0; i < 32; i++) {
            int tar = (1 << i);
            if ((m & tar) > 0 and 
                (n & tar) > 0 and
                dis <= tar) {
                ret += tar;
            }
        }
        return ret;
    }
};
