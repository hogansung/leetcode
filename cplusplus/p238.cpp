class Solution {
public:
    const long long mod = 2147483647;
    
    int power(int x, int t) {
        long long ret = 1;
        long long mul = x;
        for (int i = 0; i < 32; i++) {
            if (t % 2 == 1) {
                ret = ret * mul % mod;
            }
            mul = mul * mul % mod;
            t >>= 1;
        }
        return ret;
    }
    
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        int zero_idx = -1;
        int n_neg = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zero_idx = i;
            } else if (nums[i] < 0) {
                n_neg += 1;
            }
        }
        
        if (zero_idx != -1) {
            vector<int> ret = vector<int>(n, 0);
            ret[zero_idx] = 1;
            for (int i = 0; i < n; i++) {
                if (i == zero_idx) {
                    // do nothing
                } else {
                    ret[zero_idx] *= nums[i];
                }
            }
            return ret;
        } else {
            vector<int> revs(n, 1);
            for (int i = 0; i < n; i++) {
                revs[i] = power(nums[i], mod - 2);
            }
            
            long long mul = 1;
            for (int i = 0; i < n; i++) {
                mul = mul * nums[i] % mod;
            }
            
            vector<int> ret(n, 1);
            for (int i = 0; i < n; i++) {
                ret[i] = mul * revs[i] % mod;
            }
            return ret;
        } 
    }
};
