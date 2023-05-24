class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) {
            return false;
        }
        
        long long sum = 0;
        for (int i = 1; i <= sqrt(num); i++) {
            if (num % i == 0) {
                sum += i;
                sum += num / i;
            }
        }
        return sum == 2 * num;
    }
};
