// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long l = 1;
        long long r = n;
        while (l < r) {
            long long m = (l + r) / 2;
            if (isBadVersion(m) == true) {
                r = m;
            } else {
                l = m+1;
            }
        }
        return l;
    }
};
