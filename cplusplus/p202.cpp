class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> us;
        while (n != 1) {
            if (us.find(n) != us.end()) {
                return false;
            } else {
                us.emplace(n);
            }
            int ns = 0;
            while (n) {
                ns += (n%10) * (n%10);
                n /= 10;
            }
            n = ns;
            printf("%d\n", n);
        }
        return true;
    }
};
