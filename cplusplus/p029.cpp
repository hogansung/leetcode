class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend ==INT_MIN and divisor == -1) {
            return INT_MAX;
        } else {
            long long dividendLL = dividend;
            long long divisorLL = divisor;
            
            bool sign = false;
            if (dividendLL < 0) {
                dividendLL *= -1;
                sign ^= true;
            }
            if (divisorLL < 0) {
                divisorLL *= -1;
                sign ^= true;
            }
            
            vector<long long> vct;
            vct.emplace_back(divisorLL);
            for (int i = 1; i < 32; i++) {
                vct.emplace_back(vct[i-1] + vct[i-1]);
            }
            
            long long ret = 0;
            for (int i = 31; i >= 0; i--) {
                if (dividendLL >= vct[i]) {
                    ret += (1 << i);
                    dividendLL -= vct[i];
                }
            }
            
            if (sign == true) {
                return -ret;
            } else {
                return ret;
            }
        }
    }
};
