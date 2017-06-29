class Solution {
public:
    double myPow(double x, int n) {
        bool sign = false;
        if (n < 0) {
            sign = true;
            n *= -1;
        }
        
        vector<double> vct(32, 1);
        vct[0] = x;
        for (int i = 1; i < 32; i++) {
            vct[i] = vct[i-1] * vct[i-1];
        }
        
        double ret = 1;
        for (int i = 0; i < 32; i++) {
            int val = 1 << i;
            if (n & val) {
                ret *= vct[i];
            }
        }
        
        if (sign == true) {
            return 1.0 / ret;
        } else {
            return ret;
        }
    }
};
