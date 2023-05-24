class Solution {
public:
    int findNthDigit(int n) {
        vector<int> deg(10, 0);
        vector<long long> val(10, 1);
        vector<long long> sum(10, 0);
        for (int i = 1; i < 10; i++) {
            deg[i] = i;
            val[i] = val[i-1] * 10;
            sum[i] = sum[i-1] + (val[i] - val[i-1]) * deg[i];
            printf("%lld\n", sum[i]);
        }
        
        int l = 0;
        int r = 9;
        while (l < r) {
            int m = (l + r) / 2 + 1;
            if (n > sum[m]) {
                l = m;
            } else {
                r = m-1;
            }
        }

        n = n - sum[l] - 1;
        int d = n % deg[l+1];
        n /= deg[l+1];
        
        if (d == 0) {
            return n % val[l+1-d] / val[l-d] + 1;
        } else {
            return n % val[l+1-d] / val[l-d];
        }
        return 0;
    }
};
