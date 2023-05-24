class Solution {
public:
    int gcd(int a, int b) {
        if (b % a == 0) {
            return a;
        } else {
            return gcd(b%a, a);
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        if (n == 0 or k == 0) {
            // do nothing
        } else {
            int mv = gcd(n, k);
            for (int i = 0; i < mv; i++) {
                int val = nums[i];
                for (int j = 0; j < n/mv; j++) {
                    nums[(i+j*(n-k))%n] = nums[(i+(j+1)*(n-k))%n];
                }
                nums[(i+k)%n] = val;
            }
        }
    }
};
