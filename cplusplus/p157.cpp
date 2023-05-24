// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int sum = 0;
        while (n) {
            int val = min(n, read4(buf));
            n -= val;
            buf += val;
            sum += val;
            if (val < 4) {
                break;
            }
        }
        return sum;
    }
};
