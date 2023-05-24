class Solution {
public:
    string convertToTitle(int n) {
        string ret;
		do {
            n -= 1;
            ret.push_back('A' + n % 26);
            n /= 26;
        } while (n);
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
